package Socket;
import java.io.*;
import java.net.*;


public class FactorialServer {
    public static void main(String[] args) {
        try {
            // Create a server socket that listens on port 1234
            ServerSocket serverSocket = new ServerSocket(1234);
            System.out.println("Server started and waiting for client connection...");

            // Accept a client connection
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected!");

            // Create input and output streams for communication
            BufferedReader input = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter output = new PrintWriter(clientSocket.getOutputStream(), true);

            // Read the integer sent by the client
            String inputValue = input.readLine();
            int number = Integer.parseInt(inputValue);
            System.out.println("Received number: " + number);

            // Calculate factorial
            long factorial = calculateFactorial(number);

            // Send the result back to the client
            output.println(factorial);
            System.out.println("Factorial sent to client: " + factorial);

            // Close the connection
            input.close();
            output.close();
            clientSocket.close();
            serverSocket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // Method to calculate factorial
    private static long calculateFactorial(int number) {
        long result = 1;
        for (int i = 1; i <= number; i++) {
            result *= i;
        }
        return result;
    }
}

