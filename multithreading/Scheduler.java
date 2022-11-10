package com.multithreading;


import java.util.PriorityQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class Scheduler {
    private final PriorityQueue<DelayedTask> queue;
    private final ReentrantLock lock;
    private final Condition available;
    private final ExecutorService pool;

    public Scheduler(ExecutorService pool) {
        this.pool = pool;
        this.queue = new PriorityQueue<>();
        this.lock = new ReentrantLock();
        this.available = lock.newCondition();
        this.startExecute();
    }


    private void startExecute() {
        Runnable execute = () -> {
            while (true) {
                try {
                    DelayedTask task = take();
                    task.getTask().run();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };
        pool.execute(execute);
        pool.execute(execute);
        pool.execute(execute);

    }

    public void scheduleWithDelay(Runnable r, long delay){
        DelayedTask delayedTask = new DelayedTask(delay, r);
        this.put(delayedTask);
    }

    private Boolean put(DelayedTask task) {
        lock.lock();
        try {
            queue.offer(task);
            if (task == queue.peek()) {
                available.signal();
            }
            return true;
        } finally {
            lock.unlock();
        }
    }

    private DelayedTask take() throws InterruptedException {
        lock.lock();
        try {
            while (true) {
                if (queue.isEmpty()) {
                    available.await();
                }
                DelayedTask task = queue.peek();
                long delay = task.getDelay();
                if (delay <= 0) {
                    DelayedTask taskToBeExecuted = queue.poll();
                    if(queue.peek() != null)
                        available.signal();
                    return taskToBeExecuted;
                }
                available.awaitNanos(TimeUnit.NANOSECONDS.convert(delay, TimeUnit.MILLISECONDS));
            }
        } finally {
            lock.unlock();
        }
    }
}
