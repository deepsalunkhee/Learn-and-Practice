import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.concurrent.locks.ReentrantLock;

public class DistributedResourceManager {
    // Total number of resources
    private static final int TOTAL_RESOURCES = 5;
    
    // Number of processes
    private static final int TOTAL_PROCESSES = 10;
    
    // Resource locks to prevent race conditions
    private static final List<ReentrantLock> resourceLocks = new ArrayList<>();
    
    // Tracking resource allocation
    private static final boolean[] resourceAllocated = new boolean[TOTAL_RESOURCES];
    
    public static class Process implements Runnable {
        private final int processId;
        private final Random random;
        
        public Process(int processId) {
            this.processId = processId;
            this.random = new Random();
        }
        
        @Override
        public void run() {
            try {
                // Simulate work and resource requests
                while (!Thread.currentThread().isInterrupted()) {
                    int resourceId = requestResource();
                    if (resourceId != -1) {
                        // Simulate work with the resource
                        performWork(resourceId);
                        
                        // Release the resource
                        releaseResource(resourceId);
                        
                        // Random delay to simulate different process behaviors
                        Thread.sleep(random.nextInt(1000) + 500);
                    }
                }
            } catch (InterruptedException e) {
                System.out.println("Process " + processId + " interrupted.");
            }
        }
        
        private synchronized int requestResource() {
            for (int i = 0; i < TOTAL_RESOURCES; i++) {
                // Use a lock to ensure thread-safe resource allocation
                resourceLocks.get(i).lock();
                try {
                    if (!resourceAllocated[i]) {
                        resourceAllocated[i] = true;
                        System.out.println("Process " + processId + " acquired resource " + i);
                        return i;
                    }
                } finally {
                    resourceLocks.get(i).unlock();
                }
            }
            return -1; // No available resources
        }
        
        private void performWork(int resourceId) throws InterruptedException {
            // Simulate some work being done with the resource
            System.out.println("Process " + processId + " working with resource " + resourceId);
            Thread.sleep(random.nextInt(500) + 200);
        }
        
        private synchronized void releaseResource(int resourceId) {
            resourceLocks.get(resourceId).lock();
            try {
                resourceAllocated[resourceId] = false;
                System.out.println("Process " + processId + " released resource " + resourceId);
            } finally {
                resourceLocks.get(resourceId).unlock();
            }
        }
    }
    
    public static void main(String[] args) {
        // Initialize resource locks
        for (int i = 0; i < TOTAL_RESOURCES; i++) {
            resourceLocks.add(new ReentrantLock());
        }
        
        // Create and start processes
        List<Thread> processes = new ArrayList<>();
        for (int i = 0; i < TOTAL_PROCESSES; i++) {
            Thread processThread = new Thread(new Process(i));
            processThread.start();
            processes.add(processThread);
        }
        
        // Let the simulation run for a while
        try {
            Thread.sleep(10000); // Run for 10 seconds
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        // Interrupt all processes
        processes.forEach(Thread::interrupt);
        
        // Wait for all processes to terminate
        processes.forEach(thread -> {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });
        
        System.out.println("Distributed resource simulation completed.");
    }
}