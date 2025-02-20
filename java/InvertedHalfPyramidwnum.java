import java.util.Scanner;

public class InvertedHalfPyramidwnum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input n");
        int n = sc.nextInt(); // You can change the value of n to print a different-sized pyramid
        printInvertedHalfPyramid(n);
    }

    public static void printInvertedHalfPyramid(int n) {
        for (int i = 1; i <= n; i++) {
            // Print numbers
            for (int j = 1; j <= n - i + 1 ; j++) {
                System.out.print(j + " ");
            }
            // new line
            System.out.println();
        }
    }
}
