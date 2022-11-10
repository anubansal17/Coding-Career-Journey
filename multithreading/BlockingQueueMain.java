package com.multithreading;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import static java.time.LocalTime.now;

/*
Problem Statement: Design a delay queue class. We can put {Runnable, delay (in ms)} into the queue. The runnable has to be executed after the given delay. For execution, write a custom executor rather than using ExecutorService directly.

Present the interface method void scheduleWithDelay(Runnable r, long delayMillis), ask if the candidate is familiar with Java and the Runnable interface. If not, give the equivalent (e.g., function pointer). Give an example of the expected behavior:

example input sequence:


scheduleWithDelay(() => println("bye"), 5000L)
sleep(1000)
scheduleWithDelay(() => println("hi"), 3000L)
example output sequence:


hi # at time 4000
bye # at time 5000
Tell the candidate that they can use basic data structures from core libraries and basic concurrency primitives such as Threads, Locks, sleep, and currentTimeMillis, but nothing else. Ask for actual code in their language of choice but you can be lenient with knowledge of core libraries as long as reasonable assumptions for behavior of core libraries is assumed.

 */
public class Main {

    public static void main(String[] args) throws InterruptedException {
        ExecutorService pool = Executors.newFixedThreadPool(10);
        Scheduler scheduler = new Scheduler(pool);
        scheduler.scheduleWithDelay(() -> System.out.println("bye" + " @" + now()), 5000L);
        Thread.sleep(1000);
        scheduler.scheduleWithDelay(() -> System.out.println("hi" + " @" + now()), 3000L);
        pool.shutdown();
    }
}
