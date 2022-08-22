import java.util.Scanner;

//To find if the number ispresent i the array or not
public class branchloop {

    public static void main(String x[]) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the size of the array");
        int n = sc.nextInt();

        int array[] = new int[n];

        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }

        System.out.println("Enter element to be search");

        int z = sc.nextInt();
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (z == array[i]) {
                c++;
                break;
            }
        }

        if (c != 0) {
            System.out.println("Element exist");
        } else {

            System.out.println("Element does not exst");

        }

        sc.close();

    }

}
