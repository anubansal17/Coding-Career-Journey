package com.multithreading;

public interface IScheduler {
    void scheduleWithDelay(Runnable r, long delayMillis) throws InterruptedException;
}
