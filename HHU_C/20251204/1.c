#include<stdio.h>
int main(){
    int a = 10;double b = 20.114;
    double *p2 = &b;
    int *p = &a;
    printf("%p %d %p %f\n",p,*p,p2,*p2);
    printf("%llu %llu",sizeof(p),sizeof(p2));
}