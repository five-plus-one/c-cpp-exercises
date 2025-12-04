#include<stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    if(n>=60 && n<=100){
        printf("Pass");
    }else if(n>=0){
        printf("No Pass");
    }else{
        printf("Data Error");
    }
    return 0;

}