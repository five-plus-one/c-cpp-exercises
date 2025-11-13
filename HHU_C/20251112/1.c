#include<stdio.h>
int max2(int a,int b){
    return a>b?a:b;
}
int max4(int a,int b,int c,int d){
    return max2(max2(a,b),max2(c,d));
}

int main(void){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    printf("最大的事:%d",max4(a,b,c,d));
    return 0;
}