package com.multithreading;

public class JobThread implements Runnable{
    long delay = 0;
    Runnable runnable;

    JobThread(long delay, Runnable r) {
        this.delay = delay;
        this.runnable = r;
    }
    @Override
    public void run() {
        try {
            Thread thread = new Thread(runnable);
            Thread.sleep(delay);
            thread.start();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
