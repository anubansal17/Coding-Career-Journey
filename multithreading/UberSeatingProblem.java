package com.multithreading;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
/*
Imagine at the end of a political conference, republicans and democrats are trying to leave the venue and ordering Uber rides at the same time.
However, to make sure no fight breaks out in an Uber ride, the software developers at Uber come up with an algorithm whereby either an Uber ride can have all democrats or republicans or two Democrats and two Republicans.
All other combinations can result in a fist-fight.

Your task as the Uber developer is to model the ride requestors as threads.
Once an acceptable combination of riders is possible, threads are allowed to proceed to ride.
Each thread invokes the method seated() when selected by the system for the next ride. When all the threads are seated, any one of the four threads can invoke the method drive() to inform the driver to start the ride.
 */
public class UberSeatingProblem {

    private int republicans = 0;
    private int democrats = 0;
    CyclicBarrier barrier = new CyclicBarrier(4);
    ReentrantLock lock = new ReentrantLock();
    Semaphore demosWaiting = new Semaphore(0);
    Semaphore repubsWaiting = new Semaphore(0);

    void seatDemocrat() throws InterruptedException, BrokenBarrierException {
        boolean isLeader = false;
        lock.lock();
        democrats ++;
        if(democrats == 4) {
            demosWaiting.release(3);
            democrats = 0;
            isLeader = true;
        } else if(democrats == 2 && republicans >= 2) {
            demosWaiting.release(1);
            repubsWaiting.release(2);
            democrats = 0;
            republicans -= 2;
            isLeader = true;
        } else {
            lock.unlock();
            demosWaiting.acquire();
        }
        seated();
        barrier.await();
        if(isLeader) {
            drive();
            lock.unlock();
        }
    }

    void seatRepublican() throws InterruptedException, BrokenBarrierException {
        boolean isLeader = false;
        lock.lock();
        republicans ++;
        if(republicans == 4) {
            repubsWaiting.release(3);
            republicans = 0;
            isLeader = true;
        } else if(republicans == 2 && democrats >= 2) {
            repubsWaiting.release(1);
            demosWaiting.release(2);
            republicans = 0;
            democrats -= 2;
            isLeader = true;
        } else {
            lock.unlock();
            repubsWaiting.acquire();
        }
        seated();
        barrier.await();
        if(isLeader) {
            drive();
            lock.unlock();
        }
    }

    void seated() {
    }

    void drive() {
    }
}
