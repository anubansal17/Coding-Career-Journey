package com.multithreading;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.ReentrantLock;

class BarberShopProblem {

    final int CHAIRS = 3;
    int waitingCustomers = 0;
    Semaphore isBarberDone = new Semaphore(0);
    Semaphore isBarberWaiting = new Semaphore(0);
    ReentrantLock lock = new ReentrantLock();

    void customerWalksIn() throws InterruptedException {
        lock.lock();
        if (waitingCustomers == CHAIRS) {
            System.out.println("Customer walks out, all chairs occupied.");
            lock.unlock();
            return;
        }
        waitingCustomers++;
        lock.unlock();
        isBarberWaiting.release();
        isBarberDone.acquire();
        lock.lock();
        waitingCustomers--;
        lock.unlock();
    }

    void barber() throws InterruptedException {
        while (true) {
            isBarberWaiting.acquire();
            System.out.println("katega tumhara bhi");
            Thread.sleep(50);
            System.out.println("Kaat diya");
            isBarberDone.release();
        }
    }
}
