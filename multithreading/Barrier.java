package multithreading;

public class Barrier {
    int count = 0;
    int totalThreads;
    int released = 0;

    Barrier(int totalThreads) {
        this.totalThreads = totalThreads;
    }

    public synchronized void await() throws InterruptedException {
        while (count == totalThreads)
            this.wait();

       count++;
       if(count == totalThreads){
           this.notifyAll();
           released = totalThreads;
       } else {
           while(count < totalThreads)
               this.wait();
       }

       released--;
       if(released == 0) {
           count = 0;
           notifyAll();
       }
    }

}
