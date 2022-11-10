package multithreading;

/*
Approach1 : This can lead to starvation of writers as there is less chances of having 0 readers in the system
 */
//public class ReadWriteLock {
//    int readers;
//    boolean isWriterAccessing;
//
//    ReadWriteLock() {
//        readers = 0;
//        isWriterAccessing = false;
//    }
//
//    public synchronized void acquireReadLock() throws InterruptedException {
//        while (isWriterAccessing)
//            this.wait();
//        readers++;
//    }
//
//    public synchronized void releaseReadLock() {
//        readers--;
//        if(readers == 0)
//            this.notify();
//    }
//
//    public synchronized void acquireWriteLock() throws InterruptedException {
//        while (isWriterAccessing || readers > 0)
//            this.wait();
//        isWriterAccessing = true;
//    }
//
//    public synchronized void releaseWriteLock() {
//        isWriterAccessing = false;
//        this.notify();
//    }
//}
/*
Approach 2: To solve for writer starvation, we are keeping count of write requests in the system that are currently waiting
No reader will be given monitor if there are any waiting write requests in the system
Limitation:
Doesn't solve for reentrant lock: If a reader which had a lock requests for lock again, it won't get and will go in deadlock
Same is the case with writer, if a writer requests again for the lock while holding it, it won't get
Also, if a thread which had write lock and needs to get read lock as well, then it should be allowed in the system but below code doesn't ensure that
Also, there can be a case when a reader who had read access, needs a write access too. This reader should be granted the access if this is the only reader in the system
 */
//public class ReadWriteLock {
//    int readers;
//    boolean isWriterAccessing;
//    int writeRequests;
//
//    ReadWriteLock() {
//        readers = 0;
//        isWriterAccessing = false;
//        writeRequests = 0;
//    }
//
//    public synchronized void acquireReadLock() throws InterruptedException {
//        while (isWriterAccessing && writeRequests > 0)
//            this.wait();
//        readers++;
//    }
//
//    public synchronized void releaseReadLock() {
//        readers--;
//        if(readers == 0)
//            this.notifyAll();
//    }
//
//    public synchronized void acquireWriteLock() throws InterruptedException {
//        writeRequests++;
//        while (isWriterAccessing || readers > 0)
//            this.wait();
//        writeRequests--;
//        isWriterAccessing = true;
//    }
//
//    public synchronized void releaseWriteLock() {
//        isWriterAccessing = false;
//        this.notifyAll();
//    }
//}
/*
Approach 3: Reentrant Lock
 */
import java.util.HashMap;
import java.util.Map;

public class ReadWriteLock {
    int readers;
    Map<Thread, Integer> readersMap;
    Thread writerThread;
    boolean isWriterAccessing;
    int writeRequests;
    int writeAccesses;

    ReadWriteLock() {
        readersMap = new HashMap<>();
        readers = 0;
        isWriterAccessing = false;
        writeRequests = 0;
        writerThread = null;
        writeAccesses = 0;
    }

    public synchronized void acquireReadLock() throws InterruptedException {
        Thread currentThread = Thread.currentThread();
        while (!canGrantReadAccess(currentThread))
            this.wait();
        Integer readerCount = readersMap.get(currentThread);
        if(readerCount == null)
            readerCount = 0;
        readersMap.put(currentThread, readerCount+1);
        readers++;
    }

    public synchronized void releaseReadLock() {
        Thread currentThread = Thread.currentThread();
        readers--;
        Integer readerCount = readersMap.get(currentThread);
        if(readerCount == 1) {
            readersMap.remove(currentThread);
        } else {
            readersMap.put(currentThread, readerCount-1);
        }
        if(readers == 0)
            this.notifyAll();
    }

    public synchronized void acquireWriteLock() throws InterruptedException {
        Thread currentThread = Thread.currentThread();
        writeRequests++;
        while (!canGrantWriteAccess(currentThread))
            this.wait();
        writeRequests--;
        isWriterAccessing = true;
        writeAccesses++;
        writerThread = currentThread;
    }

    public synchronized void releaseWriteLock() {
        writeAccesses--;
        if(writeAccesses == 0) {
            isWriterAccessing = false;
            writerThread= null;
        }
        this.notifyAll();
    }

    private boolean canGrantReadAccess(Thread thread) {
        if(writerThread == thread) return true;
        if(isWriterAccessing) return false;
        if(readersMap.get(thread) != null) return true;
        return writeRequests == 0;
    }

    private boolean canGrantWriteAccess(Thread thread) {
        if(writerThread == thread) return true;
        if(isWriterAccessing) return false;
        if(readersMap.size() == 1 && readersMap.get(thread) != null) return true;
        return  false;
    }
}
