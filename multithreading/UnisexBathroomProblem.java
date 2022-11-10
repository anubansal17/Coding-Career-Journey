package multithreading;

import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
class UnisexBathroom {

    int employeesInBathroom;
    String inUseBy;
    int capacity = 3;
    ReentrantLock lock = new ReentrantLock();
    Condition needBathroom;
    Semaphore empsCount;

    UnisexBathroom(int capacity) {
        this.capacity = capacity;
        inUseBy = "NONE";
        this.employeesInBathroom = 0;
        needBathroom = lock.newCondition();
        empsCount = new Semaphore(capacity);
    }
    public void maleUseBathroom(String name) throws InterruptedException {
        lock.lock();
        while (inUseBy.equals("FEMALE") || employeesInBathroom >= capacity) {
            needBathroom.await();
        }
        employeesInBathroom++;
        empsCount.acquire();
        inUseBy = "MALE";
        lock.unlock();

        useBathroom(name);

        lock.lock();
        empsCount.release();
        employeesInBathroom--;
        if(employeesInBathroom == 0)
            inUseBy = "NONE";
        needBathroom.signalAll();
        lock.unlock();
    }

    public void femaleUseBathroom(String name) throws InterruptedException {
        lock.lock();
        System.out.println("hji");
        while (inUseBy.equals("MALE") || employeesInBathroom >= capacity) {
            needBathroom.await();
        }
        System.out.println("2hji");
        employeesInBathroom++;
        empsCount.acquire();
        inUseBy = "FEMALE";
        lock.unlock();

        useBathroom(name);

        lock.lock();
        empsCount.release();
        employeesInBathroom--;
        if(employeesInBathroom == 0)
            inUseBy = "NONE";
        needBathroom.signalAll();
        lock.unlock();
    }

    private void useBathroom(String name) throws InterruptedException {
        System.out.println("\n" + name + " using bathroom. Current employees in bathroom = " + employeesInBathroom + " " + System.currentTimeMillis());
        Thread.sleep(100);
        System.out.println("\n" + name + " done using bathroom " + System.currentTimeMillis());
    }

    public static void runTest() throws InterruptedException {

        final UnisexBathroom unisexBathroom = new UnisexBathroom(3);

        Thread female1 = new Thread(new Runnable() {
            public void run() {
                try {
                    unisexBathroom.femaleUseBathroom("Lisa");
                } catch (InterruptedException ie) {

                }
            }
        });

        Thread male1 = new Thread(new Runnable() {
            public void run() {
                try {
                    unisexBathroom.maleUseBathroom("John");
                } catch (InterruptedException ie) {

                }
            }
        });

        Thread male2 = new Thread(new Runnable() {
            public void run() {
                try {
                    unisexBathroom.maleUseBathroom("Bob");
                } catch (InterruptedException ie) {

                }
            }
        });

        Thread male3 = new Thread(new Runnable() {
            public void run() {
                try {
                    unisexBathroom.maleUseBathroom("Anil");
                } catch (InterruptedException ie) {

                }
            }
        });

        Thread male4 = new Thread(new Runnable() {
            public void run() {
                try {
                    unisexBathroom.maleUseBathroom("Wentao");
                } catch (InterruptedException ie) {

                }
            }
        });

        female1.start();
        male1.start();
        male2.start();
        male3.start();
        male4.start();

        female1.join();
        male1.join();
        male2.join();
        male3.join();
        male4.join();

    }
    public static void main( String args[] ) throws InterruptedException {
        UnisexBathroom.runTest();
    }
}
/*
MALE USE BATHROOM() :)

1. Check UseBy (either male or null i.e. not by female) and
EmpsInBathroom < max

2. If not true, wait, c'mon it won't take long its ok

3. Whwn condition becomes true, increase capacity & use bathroom by acquiring semaphore

4. Release semaphore

5. Decrease EmpsInBathroom

6. When EmpsInBathroom == 0, set useBy as null

7. signal all waiting threads


 */
