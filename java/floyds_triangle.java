import java.util.Scanner;

public class floyds_triangle {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input n");
        int n = sc.nextInt(); // You can change the value of n to print a different-sized pyramid
        printflyodstriangle(n);
    }

    public static void printflyodstriangle(int n) {
        int k=1;
        for (int i = 1; i <= n; i++) {
            // Print numbers
            for (int j = 1; j <= i ; j++) {
                System.out.print(k + " ");
                k++;
            }
            // new line
            System.out.println();
        }
    }
}
