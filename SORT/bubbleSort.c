#include<stdio.h>
int main(){
   int i,j,n,temp;
   printf("Enter number of Elements :");
   scanf("%d",&n);
   printf("Enter the Elements of the array :\n");
   int a[n];
   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
   }
   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
         }
      }
   }
   printf("After bubble sort :\n");
   for(i=0;i<n;i++){
      printf("%d ",a[i]);
   }
   printf("\n");
}
