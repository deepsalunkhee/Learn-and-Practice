package Socket;
import java.io.*;
import java.net.*;

public class FactorialClient {
    public static void main(String[] args) {
        try {
            // Connect to the server running on localhost and port 1234
            Socket socket = new Socket("localhost", 1234);
            System.out.println("Connected to server!");

            // Create input and output streams for communication
            BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader serverInput = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            // Ask user for an integer input
            System.out.print("Enter a number to calculate its factorial: ");
            int number = Integer.parseInt(input.readLine());

            // Send the number to the server
            output.println(number);

            // Receive the factorial result from the server
            String result = serverInput.readLine();
            System.out.println("Factorial of " + number + " is: " + result);

            // Close the streams and socket
            input.close();
            output.close();
            serverInput.close();
            socket.close();

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

