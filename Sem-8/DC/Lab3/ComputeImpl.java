import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

// Implementation of Compute interface
public class ComputeImpl extends UnicastRemoteObject implements Compute {

    // Constructor
    protected ComputeImpl() throws RemoteException {
        super();
    }

    // Factorial calculation
    @Override
    public int factorial(int number) throws RemoteException {
        if (number == 0 || number == 1) return 1;
        return number * factorial(number - 1);
    }
}

