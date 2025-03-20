import java.io.*;
import java.net.*;
import java.util.*;

class MutualExclusionNode {
    private int nodeId;
    private int totalNodes;
    private boolean requestingCS;
    private Set<Integer> repliesReceived;
    private ServerSocket serverSocket;
    private List<Integer> otherNodes;

    public MutualExclusionNode(int nodeId, int totalNodes) throws IOException {
        this.nodeId = nodeId;
        this.totalNodes = totalNodes;
        this.requestingCS = false;
        this.repliesReceived = new HashSet<>();
        this.otherNodes = new ArrayList<>();
        this.serverSocket = new ServerSocket(5000 + nodeId);

        for (int i = 0; i < totalNodes; i++) {
            if (i != nodeId) {
                otherNodes.add(i);
            }
        }
    }

    public void startListener() {
        new Thread(() -> {
            try {
                while (true) {
                    Socket socket = serverSocket.accept();
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    String message = in.readLine();
                    handleMessage(message);
                    socket.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }).start();
    }

    private void handleMessage(String message) {
        String[] parts = message.split(" ");
        String type = parts[0];
        int senderId = Integer.parseInt(parts[1]);
        
        if (type.equals("REQUEST")) {
            sendReply(senderId);
        } else if (type.equals("REPLY")) {
            repliesReceived.add(senderId);
        }
    }

    private void sendReply(int targetId) {
        sendMessage(targetId, "REPLY " + nodeId);
    }

    private void sendMessage(int targetId, String message) {
        try {
            Socket socket = new Socket("localhost", 5000 + targetId);
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            out.println(message);
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void requestCriticalSection() {
        requestingCS = true;
        repliesReceived.clear();

        for (int node : otherNodes) {
            sendMessage(node, "REQUEST " + nodeId);
        }

        while (repliesReceived.size() < totalNodes - 1) {
            // Waiting for replies
        }

        enterCriticalSection();
    }

    private void enterCriticalSection() {
        System.out.println("Node " + nodeId + " is entering the critical section.");
        try {
            Thread.sleep(2000); // Simulate work in the critical section
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Node " + nodeId + " is leaving the critical section.");
        requestingCS = false;
    }

    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            System.out.println("Usage: java MutualExclusionNode <nodeId> <totalNodes>");
            return;
        }

        int nodeId = Integer.parseInt(args[0]);
        int totalNodes = Integer.parseInt(args[1]);
        
        MutualExclusionNode node = new MutualExclusionNode(nodeId, totalNodes);
        node.startListener();
        
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Press Enter to request critical section...");
            scanner.nextLine();
            node.requestCriticalSection();
        }
    }
}
