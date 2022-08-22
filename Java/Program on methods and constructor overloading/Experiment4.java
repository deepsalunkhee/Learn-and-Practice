//

public class Experiment4 {

    public static void main(String x[]) {
        construtor c = new construtor();
        construtor k = new construtor(1);

    }

}

class construtor {
    construtor() {

        System.out.println("Hello words from default construtor");

    }

    construtor(int x) {
        if (x == 1)
            System.out.println("Hello world from parameterised constructor");
    }
}
