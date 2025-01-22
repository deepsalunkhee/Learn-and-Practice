import java.util.Scanner;

public class DR {

    public static double activationFunction(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // User Inputs
        System.out.println("Enter Number of tuples: ");
        int n = sc.nextInt();

        System.out.println("Enter the values of x:");
        double[] x = new double[n];
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextDouble();
        }

        System.out.println("Enter the value of y:");
        double y = sc.nextDouble();

        System.out.println("Enter the values of weights:");
        double[] weights = new double[n];
        for (int i = 0; i < n; i++) {
            weights[i] = sc.nextDouble();
        }

        System.out.println("Enter the learning rate: ");
        double c = sc.nextDouble();

        System.out.println("Enter the Bias: ");
        double b = sc.nextDouble();

        System.out.println("Enter the number of iterations: ");
        int iter = sc.nextInt();

        sc.close();

        // Training Loop
        for (int it = 0; it < iter; it++) {
            double z = 0;
            for (int i = 0; i < n; i++) {
                z += weights[i] * x[i];
            }

            double yPred = activationFunction(z + b);

            for (int i = 0; i < n; i++) {
                weights[i] += c * (y - yPred) * x[i];
            }

            b += c * (y - yPred);
        }

        // Output Results
        double zFinal = 0;
        for (int i = 0; i < n; i++) {
            zFinal += weights[i] * x[i];
        }
        double yPredFinal = activationFunction(zFinal + b);

        System.out.printf("Original Value: %.2f, Predicted Value: %.2f\n", y, yPredFinal);
    }
}
