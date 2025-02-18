import java.util.*;
public class java1 {
    public static boolean checkPrime(int a) {
    if(a<=1) return false;   
    if(a==2) return true;
    for(int i = 2;i<=Math.sqrt(a);i++) {
        if(a%i==0){
        return false;
           
        }
        }
    return true;    
    }

    public static void main(String[] args) {
        
    Scanner sc = new Scanner(System.in); //default line for input ability
    System.out.println("input the range");
    int n1 = sc.nextInt(); 
    int n2 = sc.nextInt();

    for(int i = n1; i <= n2; i++) {
        if(checkPrime(i)) {
            System.out.println(i + " is prime");
        }
        else {
            System.out.println(i + " is not prime");
        }
    }


     sc.close();
}
}

            
    



    



