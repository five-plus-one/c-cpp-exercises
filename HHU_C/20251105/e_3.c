#include<stdio.h>

int isprime(int n){
    if(n==0||n==1){
        return 0;
    }
    int i =2;
    while(i*i<=n){
        if(n%i==0){
            return 0;
        }
        i++;
    }
    return 1;
}
int main(void){
    for(int i=1;i<=1e4;i++){
        if(isprime(i)&&isprime(i+2)){
            printf("%d    ❤    %d\n",i,i+2);
        }
    }
        
}
