package com.multithreading;

public class DelayedTask implements Comparable<DelayedTask> {
    private final long startTime;
    private final Runnable task;

    DelayedTask(long delay, Runnable task) {
        this.task = task;
        startTime = System.currentTimeMillis() + delay;
    }

    public Runnable getTask() {
        return task;
    }

    public long getDelay() {
        return this.startTime - System.currentTimeMillis();
    }

    @Override
    public int compareTo(DelayedTask o) {
        return Long.compare(this.getDelay(), o.getDelay());
    }
}
