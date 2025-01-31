import java.rmi.Naming;
import java.rmi.registry.LocateRegistry;

public class Server {
    public static void main(String[] args) {
        try {
            // Create a Compute object
            Compute compute = new ComputeImpl();

            // Start RMI registry on port 5000
            LocateRegistry.createRegistry(5000);

            // Bind the Compute object to a name
            Naming.rebind("rmi://localhost:5000/ComputeService", compute);

            System.out.println("Server is ready.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

