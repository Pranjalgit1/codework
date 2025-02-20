import java.util.*;

public class arrayLargeSmallvalues {
    public static void main(String[] args) {
        int number[]={1,2,3,4,5,6};
        System.out.println("largest value:" + largest(number) );

       
    }

    public static int largest(int number[]) {
        int largest=Integer.MIN_VALUE;
        int smallest=Integer.MAX_VALUE;
        for(int i=0;i<number.length;i++) {
            if(number[i]>largest){
                largest=number[i];
            }
            if(number[i]<smallest){
                smallest=number[i];
            }
        }
        System.out.println("Smallest Number: " + smallest);
        return largest;
       
      
       
}


}

