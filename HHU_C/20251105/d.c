#include<stdio.h>
int calGCD(int a,int b){
    while(b){
        int tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}
int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d",calGCD(a,b));
}