import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.*;

/**
 * Multithread version web crawler.
 *
 * Use a Lock and a non_empty condition to implement a multithreaded web crawler. The crucial part
 * is how to notify every thread that there is no more work and should stop.
 *
 * A few pitfalls
 * 1. Use Condition#signalAll. The #notifyAll method is for Object.
 */
public class WebCrawlerMultithread {
  public static void main(String[] args) {
    WebCrawlerMultithread crawler = new WebCrawlerMultithread(3, 10);
    Set<String> links = crawler.crawl("https://www.zhihu.com/question/318198303");
    System.out.println(links);
    System.out.println("finished");
  }

  private final Queue<String> que;
  private final Set<String> visited;
  private final int nThreads;
  private int activeThreads;
  private final ExecutorService executorService;
  private final Lock lock;
  private final Condition nonEmpty;
  private final int maxCount;

  private WebCrawlerMultithread(int nThreads, int maxCount) {
    this.nThreads = nThreads;
    this.activeThreads = nThreads;
    this.que = new LinkedList<>();
    this.visited = new HashSet<>();
    this.executorService = Executors.newFixedThreadPool(nThreads);
    this.lock = new ReentrantLock();
    this.nonEmpty = lock.newCondition();
    this.maxCount = maxCount;
  }

  private Set<String> crawl(String startingUrl) {
    que.offer(startingUrl);
    for (int i = 0; i < nThreads; i++) {
      executorService.submit(this::work);
    }

    try {
      executorService.awaitTermination(60, TimeUnit.SECONDS);
    } catch (Exception e) {
    } finally {
      executorService.shutdown();
    }
    return visited;
  }

  private void work() {
    try {
      while (true) {
        String url = takeUrl();
        if (url == null) {
          System.out.println(Thread.currentThread().getId() + " finished");
          break;
        }
        addUrls(WebCrawler.getLinks(url));
      }
    } catch (Exception e) {
    }
  }

  private String takeUrl() {
    lock.lock();
    try {
      activeThreads--;
      while (que.isEmpty()) {
        if (activeThreads == 0) return null;
        nonEmpty.await();
      }
      activeThreads++;
      return que.poll();
    } catch (Exception e) {
      return null;
    } finally {
      lock.unlock();
    }
  }

  private void addUrls(List<String> links) {
    lock.lock();
    try {
      for (String link : links) {
        if (!visited.contains(link) && visited.size() < this.maxCount) {
          visited.add(link);
          que.offer(link);
        }
      }
      nonEmpty.signalAll();
    } catch (Exception e) {
    } finally {
      lock.unlock();
    }
  }
}
