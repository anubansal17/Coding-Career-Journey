package com.multithreading;

import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BlockingQueue<E> {
    private List<E> queue = new LinkedList<>();
    private int limit = 10;
    private final Lock lock;
    private final Condition notFull;
    private final Condition notEmpty;

    BlockingQueue(int limit) {
        this.limit = limit;
        this.lock = new ReentrantLock();
        this.notFull = lock.newCondition();
        this.notEmpty = lock.newCondition();
    }

    public boolean isEmpty() {
        return queue.isEmpty();
    }

    public void enqueue(E item) throws InterruptedException{
        lock.lock();
        try {
            while (queue.size() == limit) {
                notFull.await();
            }
            if (this.queue.isEmpty())
                notEmpty.signal();
            this.queue.add(item);
            System.out.println("Enqueue done :" + queue);
        }
        finally {
            lock.unlock();
        }
    }

    public E dequeue() throws InterruptedException{
        lock.lock();
        try {
            while(this.queue.isEmpty())
                notEmpty.await();
            if(queue.size() == limit)
                notFull.signal();
            return this.queue.remove(0);
        } finally {
            lock.unlock();
        }
    }
}
