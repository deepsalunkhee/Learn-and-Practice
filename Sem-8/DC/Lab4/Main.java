import java.util.Random;
import java.util.concurrent.*;

class Node implements Callable<Integer> {
    private int nodeId;
    private int localTime;
    private Random rand = new Random();

    public Node(int nodeId) {
        this.nodeId = nodeId;
        this.localTime = 1000 + rand.nextInt(200); // Simulating different local times
    }

    public int getTime() {
        return localTime;
    }

    public void adjustTime(int offset) {
        localTime += offset;
    }

    @Override
    public Integer call() {
        return localTime;
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException, ExecutionException {
        int numNodes = 5;
        ExecutorService executor = Executors.newFixedThreadPool(numNodes);
        Node[] nodes = new Node[numNodes];
        
        for (int i = 0; i < numNodes; i++) {
            nodes[i] = new Node(i);
        }
        
        // Master node is node[0]
        Node masterNode = nodes[0];
        System.out.println("Master Node ID: 0, Time: " + masterNode.getTime());
        
        // Collect times from all nodes
        @SuppressWarnings("unchecked")
        Future<Integer>[] futures = new Future[numNodes];
        for (int i = 0; i < numNodes; i++) {
            futures[i] = executor.submit(nodes[i]);
        }
        
        // Calculate average time offset
        int totalTime = 0;
        for (Future<Integer> future : futures) {
            totalTime += future.get();
        }
        
        int avgTime = totalTime / numNodes;
        System.out.println("Calculated Average Time: " + avgTime);
        
        // Synchronize all nodes
        for (Node node : nodes) {
            int offset = avgTime - node.getTime();
            node.adjustTime(offset);
            System.out.println("Node " + node + " adjusted by " + offset + ", New Time: " + node.getTime());
        }
        
        executor.shutdown();
    }
}
