#include<stdio.h>
int fibo(int x){
    if(x == 0)
        return 0;
    if(x ==1)
        return 1;
    if(x>1)
        return fibo(x-1)+fibo(x-2);
}
int main(){
    int x,fib;
    while(1){
         scanf("%d",&x);
         fib=fibo(x);
         printf("The Fibonacci number for %d is %d\n",x,fib);
    }
    return 0;
}
