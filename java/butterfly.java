import java.util.Scanner;

public class butterfly {
    public static void main(String[] args) {
        // You can change the value of n to print a different-sized 
        pattern(4);
    }

    public static void pattern(int n) {
        //upper pattern of butterfly
        for (int i = 1; i <= n; i++) {
            //star
            for (int j = 1; j <= i ; j++) {
               System.out.print("*");
            }
            //space
            for(int k=1;k <= 2*(n-i);k++) {
            // new line
            System.out.print(" ");
        }
        // star
        for (int j = 1; j <= i ; j++) {
            System.out.print("*");
         }
         System.out.println();
    
}    
       
    // lower pattern fo butterfly just flip the limit of outer loop
    for (int i = n; i >=1; i--) {
        //star
        for (int j = 1; j <= i ; j++) {
            System.out.print("*");
        }
        //space
        for(int k=1;k <=2*(n-i);k++) {
        // new line
        System.out.print(" ");
    }
    // star
    for (int j = 1; j <= i ; j++) {
        System.out.print("*");
     }
     System.err.println();
    }
  

}

/*
THIS IS HOW THE PATTERN LOOKS LIKE
*      *
**    **
***  ***
********
********
***  ***
**    **
*      *
                      */
}

