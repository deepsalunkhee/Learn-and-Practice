import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

class Node implements Runnable {
    private final int id;
    private long localClock;
    private final Random random = new Random();

    public Node(int id) {
        this.id = id;
        this.localClock = System.currentTimeMillis(); // Initialize with system time
    }

    private void sendMessage(Node receiver) {
        long timestamp = localClock;
        System.out.println("Node " + id + " sent a message to Node " + receiver.id + " at " + timestamp);
        receiver.receiveMessage(this, timestamp);
    }

    private void receiveMessage(Node sender, long timestamp) {
        System.out.println("Node " + id + " received a message from Node " + sender.id + " with timestamp " + timestamp);
        synchronizeClock(timestamp);
    }

    private void synchronizeClock(long receivedTimestamp) {
        localClock = Math.max(localClock, receivedTimestamp) + 1;
        System.out.println("Node " + id + " updated its local clock to " + localClock);
    }

    @Override
    public void run() {
        try {
            while (true) {
                Thread.sleep(random.nextInt(3000) + 1000); // Random interval between 1-4 sec
                localClock += random.nextInt(10); // Simulate local clock drift
                Node receiver = DistributedSystem.getRandomNode(id);
                if (receiver != null) {
                    sendMessage(receiver);
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

public class DistributedSystem {
    private static final int NODE_COUNT = 5;
    private static final Node[] nodes = new Node[NODE_COUNT];
    private static final Random random = new Random();

    public static void main(String[] args) {
        ExecutorService executor = Executors.newFixedThreadPool(NODE_COUNT);
        for (int i = 0; i < NODE_COUNT; i++) {
            nodes[i] = new Node(i);
            executor.execute(nodes[i]);
        }
        try {
            Thread.sleep(20000); // Run for 20 seconds
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        executor.shutdownNow();
    }

    public static Node getRandomNode(int excludeId) {
        while (true) {
            int randomIndex = random.nextInt(NODE_COUNT);
            if (randomIndex != excludeId) {
                return nodes[randomIndex];
            }
        }
    }
}
