import java.rmi.Remote;
import java.rmi.RemoteException;

// Remote interface
public interface Compute extends Remote {
    int factorial(int number) throws RemoteException;
}

