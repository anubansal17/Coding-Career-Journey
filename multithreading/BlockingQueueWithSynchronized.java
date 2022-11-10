package com.multithreading;


public class BlockingQueueWithSynchronized<E>{
    private final E[] queue;
    private int limit = 10;
    private int size;
    private int tail;
    private int head;

    BlockingQueueWithSynchronized(int limit) {
        this.limit = limit;
        queue = (E[]) new Object[limit];
        size = 0;
        tail = 0;
        head = 0;
    }

    public void enqueue(E task) throws InterruptedException {
        synchronized (queue) {
            while (limit == size) {
                queue.wait();
            }
            if(tail == limit) {
                tail = 0;
            }
            queue[tail] = task;
            tail++;
            size++;
            queue.notifyAll();
        }
    }

    public E dequeue() throws InterruptedException {
        synchronized (queue) {
            while (size == 0)
                queue.wait();
            if(head == limit) {
                head = 0;
            }
            size--;
            queue.notifyAll();
            E task = queue[head];
            queue[head] = null;
            head++;
            return task;
        }
    }
}
