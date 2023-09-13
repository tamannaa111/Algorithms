
#include <stdio.h>

int fibonacci(int n){
    int fibo[n],i;
    fibo[0]=0,fibo[1]=1;
    
    for( i=2;i<=n+1;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
        
    }return fibo[n];
}

int main() {
    int n;
    printf("Enter your number:");
    scanf("%d",&n);
    printf("%d\n",fibonacci(n));
    
    return 0;
}
