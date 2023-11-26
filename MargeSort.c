
#include<stdio.h>
void margesort(int a[],int l,int mid,int h){
   int i,j,k,temp[20];
   i=l;
   j=mid+1;
   k=l;
   while(i<=mid&&j<=h)
   {
       if(a[i]<=a[j]){
           temp[k]=a[i];   // New array
            i++;   // left sub tree initialize increase
            k++;  // new marge tree initialize increase
       }
       else{
           temp[k]=a[j];
           j++;  //right sub tree initialize increase
           k++;
       }
   }
  if(i>mid){           // i is already fill up but j is remaining
   while(j<=h){
       temp[k]=a[j];
       j++;
       k++;
       }
   }
   else{
          while(i<=mid){   // j is already fill up but i is remaining
           temp[k]=a[i];
              i++;
              k++;
           }
   }
   for(k=l;k<=h;k++){ // copy array
       a[k]=temp[k];
   }
}
void marge(int a[],int l,int h){
   int mid;
   if(l!=h){
       mid=(l+h)/2;
       marge(a,l,mid);  //divide to left subtree
       marge(a,mid+1,h);  //divide devide to right sub tree
       margesort(a,l,mid,h);  // marge function call to marge
   }

}
int main(){
   int i,n,l,h;
   printf("Enter any number: ");
   scanf("%d",&n);
   int a[n];
   for(i=0;i<n;i++){
       scanf("%d",&a[i]);
   }
   l=0;
   h=n-1;
   marge(a,l,h);
   for(i=0;i<n;i++){
       printf("%d\t",a[i]);
   }
}


 
