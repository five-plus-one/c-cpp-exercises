#include<stdio.h>
int calGCD(int x,int y){
    if(y<x){
        return calGCD(y,x);
    }
    if(x == y){
        return x;
    }else{
        return calGCD(y-x,x);
    }
    
}
int calLCM(int x,int y){
    return x * y /calGCD(x,y);
}
int main(void){
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d %d",calGCD(a,b),calLCM(a,b));
}