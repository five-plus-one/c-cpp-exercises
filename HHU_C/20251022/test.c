#include<stdio.h>
int main(void){
    int a =5,b=2;
    int x;
    x = a>b++?++a:b++;
    printf("%d %d %d",a,b,x);
    return 0;
}