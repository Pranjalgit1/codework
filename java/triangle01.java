import java.util.Scanner;

public class triangle01 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input n");
        int n = sc.nextInt(); // You can change the value of n to print a different-sized pyramid
        triangle(n);
    }

    public static void triangle(int n) {
        
        for (int i = 1; i <= n; i++) {
            
            for (int j = 1; j <= i ; j++) {
               if((i+j)%2==0){
                System.out.print(1);
               }
               else{
                System.out.print(0);
               }
            }
            // new line
            System.out.println();
           
        }
    }
}
