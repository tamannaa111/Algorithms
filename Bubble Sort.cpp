#include<stdio.h>
int main(){
  int i,j,n,temp;
  printf("Enter any number:");
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++){    //outer loop for number of passess......iteration=n-1
    int flag=0;
      
    for(j=0;j<n-1-i;j++){    //for comparisn   ,,,,, j<n-1-i for optimization
        
        if(a[j]>a[j+1]){
            
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            flag=1;
        }
    }
    if(flag==0){
        break;   // jodi flag er value 1 na hoy tahole inner loop stop hobe
    }
  }
  for(i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  return 0;
}
