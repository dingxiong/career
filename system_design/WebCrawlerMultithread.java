import java.util.*;
import java.util.concurrent.*;
import java.util.concurrent.locks.*;

/**
 * Multithread version web crawler.
 *
 * Use a BlockingQueue, a Lock and a normal set. Note, we do not use a concurrent set because we use
 * a reentrent lock to guard the access of this set.
 */
public class WebCrawlerMultithread {
  public static void main(String[] args) {
    WebCrawlerMultithread crawler = new WebCrawlerMultithread(3, 10);
    Set<String> links = crawler.crawl("https://www.zhihu.com/question/318198303");
    System.out.println(links);
    System.out.println("finished");
  }

  private final BlockingDeque<String> bq;
  private final Set<String> visited;
  private final int nThreads;
  private final ExecutorService executorService;
  private final Lock lock;
  private final int maxCount;

  private WebCrawlerMultithread(int nThreads, int maxCount) {
    this.nThreads = nThreads;
    this.bq = new LinkedBlockingDeque<>();
    this.visited = new HashSet<>();
    this.executorService = Executors.newFixedThreadPool(nThreads);
    this.lock = new ReentrantLock();
    this.maxCount = maxCount;
  }

  private Set<String> crawl(String startingUrl) {
    bq.offer(startingUrl);
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
        String url = bq.poll(10, TimeUnit.SECONDS); // only wait for 10s
        System.out.println(Thread.currentThread().getId() + ": " + url);
        if (url == null) return;
        for (String link : WebCrawler.getLinks(url)) {
          addUrl(link);
        }
      }
    } catch (Exception e) {
    }
  }

  private void addUrl(String link) {
    lock.lock();
    try {
      if (!visited.contains(link) && visited.size() < this.maxCount) {
        visited.add(link);
        bq.put(link);
      }
    } catch (Exception e) {
    } finally {
      lock.unlock();
    }
  }
}
