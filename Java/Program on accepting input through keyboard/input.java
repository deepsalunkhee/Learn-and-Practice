import java.util.Scanner;

public class input {

    public static void main(String x[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("enter your Name");

        String name = sc.nextLine();
        System.out.println("Hi " + name);
        sc.close();

    }

}
