
import java.util.Scanner;

public class Experiment2 {

    public static void main(String[] args) {

        info i = new info();

        i.student();
        i.display();

    }

}

class info {
    String name;
    int roll;

    void student() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your name:\n");

        name = sc.next();
        System.out.println("Enter your Roll no.:\n");
        roll = sc.nextInt();

        sc.close();

    }

    void display() {
        System.out.println("Student Name:" + name);
        System.out.println("student roll no:" + roll);
    }
}
