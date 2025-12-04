#include<stdio.h>
int main(void){
    int a,b;
    scanf("%d %d",&a,&b);
    float ans = a*1.0/b;
    printf("%.2f\n",ans);
    return 0;
}