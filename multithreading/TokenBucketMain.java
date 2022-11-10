package com.multithreading;

import java.util.HashSet;
import java.util.Set;

/*
Problem Statement

This is an actual interview question asked at Uber and Oracle.

Imagine you have a bucket that gets filled with tokens at the rate of 1 token per second. The bucket can hold a maximum of N tokens. Implement a thread-safe class that lets threads get a token when one is available. If no token is available, then the token-requesting threads should block.

The class should expose an API called getToken that various threads can call to get a token
Follow Up:
    Grant tokens to threads in a FIFO order
    Generalize the solution for any rate of token generation


 */
public class Main {
    public static void main(String[] args) throws InterruptedException {
        Set<Thread> allThreads = new HashSet<Thread>();
        ITokenBucketFilter tokenBucketFilter = TokenBucketFilterWithDaemonWrapper.makeTokenBucketFilter(5);

        for(int i = 0; i < 10; i++) {

            Thread thread = new Thread(new Runnable() {
                public void run() {
                    try {
                        tokenBucketFilter.getToken();
                    } catch (InterruptedException ie) {
                        System.out.println("We have a problem");
                    }
                }
            });
            thread.setName("Thread_" + (i + 1));
            allThreads.add(thread);
        }

        for (Thread t : allThreads) {
            t.start();
        }

        for (Thread t : allThreads) {
            t.join();
        }
    }
}
