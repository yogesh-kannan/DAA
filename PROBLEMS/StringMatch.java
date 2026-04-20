import java.util.*;
public class StringMatch{
   public static void main(String[] args){
      //String text="abababaa";
      //String pattern="aa";
      Scanner in=new Scanner(System.in);
      System.out.print("Enter Text :");
      String text=in.next();
      System.out.print("Enter Pattern :");
      String pattern=in.next();
      int n=text.length();
      int m=pattern.length();
      for(int i=0;i<n-m+1;i++){
         int j;
         int k=1;
         for(j=0;j<m;j++){
            if(text.charAt(i+j)!=pattern.charAt(j)){
               k=0;
               break;
            }
         }
         if(k==1)
            System.out.println("Pattern found at index :"+i);
      }
   }
}
