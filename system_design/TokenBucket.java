/**
 * Multithread token bucket
 */
public class TokenBucket {
    public static void main(String[] args) {
      TokenBucket tokenBucket = new TokenBucket(1, 10);
      ExecutorService executorService = Executors.newFixedThreadPool(3);
  
      executorService.submit(() -> tokenBucket.getTockens(10));
      executorService.submit(() -> tokenBucket.getTockens(20));
      executorService.submit(() -> tokenBucket.getTockens(40));
  
      try {
        executorService.awaitTermination(20, TimeUnit.SECONDS);
      } catch (Exception e) {
      } finally {
        executorService.shutdown();
      }
  
      System.out.println("finished");
    }
  
    private final int fillRate;
    private final int capacity;
    private int currentSize;
    private Instant lastFillTime;
  
    private Lock lock;
    private Condition nonEmpty;
  
    TokenBucket(int fillRate, int capacity) {
      this.fillRate = fillRate;
      this.capacity = capacity;
      this.currentSize = capacity;
      lastFillTime = Instant.now();
  
      lock = new ReentrantLock();
      nonEmpty = lock.newCondition();
    }
  
    public void getTockens(int k) {
      while (k > 0) {
        lock.lock();
        try {
          k -= take(k);
          System.out.println(Thread.currentThread().getId() + " still needs " + k + " tokens");
          nonEmpty.await(k/fillRate, TimeUnit.MILLISECONDS);
        } catch (Exception e) {
        } finally {
          if (currentSize > 0) nonEmpty.signal();
          lock.unlock();
        }
      }
    }
  
    private int take(int k) {
      refill();
      if (currentSize > k) {
        currentSize -= k;
        return k;
      } else {
        int get = currentSize;
        currentSize = 0;
        return get;
      }
    }
  
    private void refill() {
      Instant now = Instant.now();
      Duration duration = Duration.between(lastFillTime, now);
      lastFillTime = now;
      currentSize = Math.min(capacity, currentSize + (int)duration.toMillis() * fillRate);
    }
  }
  