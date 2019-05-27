import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Read write lock implementation
 * Ref: https://en.wikipedia.org/wiki/Readers%E2%80%93writer_lock
 */
public class RWLock {
  private int reads = 0;
  private boolean hasWrite = false;
  private Lock lock;
  private Condition condition;

  RWLock() {
    lock = new ReentrantLock();
    condition = lock.newCondition();
  }

  void lockRead() {
    lock.lock();
    try {
      while (hasWrite) condition.await(); //
      reads++;
    } catch (Exception e) {
    } finally {
      lock.unlock();
    }
  }

  void unlockRead() {
    lock.lock();
    try {
      reads--;
    } finally {
      if (reads == 0) condition.signalAll();
      lock.unlock();
    }
  }

  void lockWrite() {
    lock.lock();
    try {
      // we check hasWrite and reads separately. if we write something like
      //     while (hasWrite || reads > 0) condition.await();
      //     hasWrite = true;
      // then there is write starvation.
      while (hasWrite) condition.await();
      hasWrite = true;
      while (reads > 0) condition.await();
    } catch (Exception e) {
    } finally {
      lock.unlock();
    }
  }

  void unlockWrite() {
    lock.lock();
    try {
      hasWrite = false;
    } finally {
      condition.signalAll(); // signal all => await all reading threads for performance
      lock.unlock();
    }
  }
}
