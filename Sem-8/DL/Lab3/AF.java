import java.util.*;

public class AF {

    public static double sigmoid(double x) {
        return 1 / (1 + Math.exp(-x));
    }

    public static double relu(double x) {
        return Math.max(0, x);
    }

    public static double tanh(double x) {
        return (Math.exp(x) - Math.exp(-x)) / (Math.exp(x) + Math.exp(-x));
    }

    public static double linear(double x) {
        return x;
    }

    public static double leakyRelu(double x) {
        return x <= 0 ? 0.01 * x : x;
    }

    public static double[] softmax(double[] x) {
        double[] fx = new double[x.length];
        double sumExp = 0;
        for (double val : x) {
            sumExp += Math.exp(val);
        }

        for (int i = 0; i < x.length; i++) {
            fx[i] = Math.exp(x[i]) / sumExp;
        }
        return fx;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

       int n=4;

        double[] x1 = {2104, 1600, 2400, 1416};
        double[] x2 = {3, 3, 3, 2};
        double[] y = {400, 330, 369, 232};
        double[] weights = new double[n];
        Random rand = new Random();
        for (int i = 0; i < n; i++) {
            weights[i] = -1 + (1 - (-1)) * rand.nextDouble(); // Random weights between -1 and 1
        }

        sc.close();

        System.out.println("Weights: " + Arrays.toString(weights));
        System.out.println("Features: x1=" + Arrays.toString(x1) + ", x2=" + Arrays.toString(x2));
        System.out.println("Target Values: y=" + Arrays.toString(y));

        List<java.util.function.Function<Double, Double>> activationFunctions = Arrays.asList(
            AF::sigmoid,
            AF::relu,
            AF::tanh,
            AF::linear,
            AF::leakyRelu
        );
        
        String[] functionNames = {"Sigmoid", "ReLU", "Tanh", "Linear", "Leaky ReLU"};
        
        for (int idx = 0; idx < activationFunctions.size(); idx++) {
            System.out.println("Activation Function: " + functionNames[idx]);
        
            double mse = 0;
            for (int i = 0; i < 4; i++) {
                double z = weights[0] * x1[i] + weights[1] * x2[i];
                double yPred = activationFunctions.get(idx).apply(z);
                mse += Math.pow(yPred - y[i], 2);
            }
            mse /= 4;
            System.out.printf("MSE: %.2f%n%n", mse);
        }
        
    }
}
