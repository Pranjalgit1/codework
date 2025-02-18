import java.util.*;
public class java1 {
    

    public static void main(String[] args) {
    int lastdigit,dec=0;    
    Scanner sc = new Scanner(System.in); //default line for input ability
   
    int num = sc.nextInt(); 
    int powr =0;
    int onum=num;    
        while(num>0){
        lastdigit = num%10;
        dec = dec + (int)(lastdigit*Math.pow(2, powr));
        num = num/10;    
        powr++;
        }
   System.out.println("Decimal of "+onum+" is "+dec);


     sc.close();
}
}

            
    



    



