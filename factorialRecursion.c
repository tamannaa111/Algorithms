//
//  main.c
//  RecurtionFactorial
//
//  Created by Tamanna Akter on 18/8/23.
//

#include <stdio.h>
int fact(int n);

int main(){
   int result=fact(5);
    printf("factorial of 5 is = %d\n",result);
}
int fact(int n){
    if(n==1)
        return 1;
    else
       return n*fact( n-1);
    
}
