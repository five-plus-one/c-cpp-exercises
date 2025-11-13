#include<stdio.h>

int fbnq(int n){
    if(n==1 || n==2){
        return 1;
    }else{
        return fbnq(n-1)+fbnq(n-2);
    }
}
int main(void){
    for(int i=1;i<=40;i++){
        printf("%d ",fbnq(i));
    }
}