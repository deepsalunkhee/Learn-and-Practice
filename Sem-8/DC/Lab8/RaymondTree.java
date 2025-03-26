import java.util.*;

class Node {
    int id;
    boolean hasToken;
    int parentId;
    Queue<Integer> requestQueue;

    public Node(int id, boolean hasToken, int parentId) {
        this.id = id;
        this.hasToken = hasToken;
        this.parentId = parentId;
        this.requestQueue = new LinkedList<>();
    }

    public void requestToken(DistributedSystem system) {
        if (!hasToken) {
            if (requestQueue.isEmpty()) {
                requestQueue.add(id);
                system.sendRequest(parentId, id);
            }
        }
    }

    public void receiveRequest(int requesterId, DistributedSystem system) {
        requestQueue.add(requesterId);
        if (hasToken) {
            sendToken(system);  // ✅ Fixed: Pass system
        } else if (requestQueue.size() == 1) {
            system.sendRequest(parentId, id);
        }
    }

    public void sendToken(DistributedSystem system) {
        if (!requestQueue.isEmpty()) {
            int nextProcess = requestQueue.poll();
            System.out.println("Process " + id + " sends token to Process " + nextProcess);
            system.sendToken(nextProcess);
            hasToken = false;
        }
    }

    public void receiveToken(DistributedSystem system) {  // ✅ Fixed: Pass system
        hasToken = true;
        System.out.println("Process " + id + " received the token.");
        sendToken(system);  // ✅ Pass system reference
    }
}

class DistributedSystem {
    Map<Integer, Node> nodes;

    public DistributedSystem() {
        nodes = new HashMap<>();
    }

    public void addNode(int id, boolean hasToken, int parentId) {
        nodes.put(id, new Node(id, hasToken, parentId));
    }

    public void sendRequest(int to, int from) {
        System.out.println("Process " + from + " requests token from " + to);
        nodes.get(to).receiveRequest(from, this);
    }

    public void sendToken(int to) {
        nodes.get(to).receiveToken(this);  // ✅ Pass 'this' to keep system reference
    }

    public void startRequest(int id) {
        nodes.get(id).requestToken(this);
    }
}

public class RaymondTree {
    public static void main(String[] args) {
        DistributedSystem system = new DistributedSystem();

        system.addNode(0, true, -1);
        system.addNode(1, false, 0);
        system.addNode(2, false, 1);
        system.addNode(3, false, 1);
        system.addNode(4, false, 2);

        System.out.println("\nProcess 4 initiates token request...\n");
        system.startRequest(4);
    }
}
