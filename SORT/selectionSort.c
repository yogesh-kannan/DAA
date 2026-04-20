#include<stdio.h>
int main(){
   int i,j,temp,min,n;
   printf("Enter number of Elements :");
   scanf("%d",&n);
   printf("Enter the Elements of the array :\n");
   int a[n];
   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++){
      min=i;
      for(j=i;j<n;j++){
         if(a[j]<a[min]){
            min=j;
         }
      }
      temp=a[i];
      a[i]=a[min];
      a[min]=temp;
   }
   printf("After selection sort :\n");
   for(i=0;i<n;i++){
      printf("%d ",a[i]);
   }
   printf("\n");
}
