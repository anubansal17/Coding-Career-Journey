package com.multithreading;

import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class BlockingQueueWithLock<E> {

    private List<E> queue = new LinkedList<>();
    private int limit = 10;
    private final Lock lock;
    private final Condition notFull;
    private final Condition notEmpty;

    BlockingQueueWithLock(int limit) {
        this.limit = limit;
        this.lock = new ReentrantLock();
        this.notFull = lock.newCondition();
        this.notEmpty = lock.newCondition();
    }

    public List<E> getQueue() {
        return queue;
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

    public void dequeue() throws InterruptedException{
        lock.lock();
        try {
            while(this.queue.isEmpty())
                notEmpty.await();
            if(queue.size() == limit)
                notFull.signal();
            this.queue.remove(0);
            System.out.println("Dequeue done :" + queue);
        } finally {
            lock.unlock();
        }
    }
}
