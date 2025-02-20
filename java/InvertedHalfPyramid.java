public class InvertedHalfPyramid {
    public static void main(String[] args) {
        int n = 4; // You can change the value of n to print a different-sized pyramid
        printInvertedHalfPyramid(n);
    }

    public static void printInvertedHalfPyramid(int n) {
        for (int i = 1; i <= n; i++) {
            // Print leading spaces
            for (int j = 1; j <= n - i ; j++) {
                System.out.print(" ");
            }
            // Print stars
            for (int k = 1; k <= i; k++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
