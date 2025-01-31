import java.rmi.Naming;

public class Client {
    public static void main(String[] args) {
        try {
            // Look up the Compute service in the RMI registry
            Compute compute = (Compute) Naming.lookup("rmi://localhost:5000/ComputeService");

            // Input number for factorial
            int number = 5; // Example input
            int result = compute.factorial(number);

            // Print the result
            System.out.println("Factorial of " + number + " is: " + result);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

