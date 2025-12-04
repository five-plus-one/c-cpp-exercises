#include<stdio.h>
#include<string.h>
int main(){
    int a = 10;double b = 20.114;
    double *p2 = &b;
    int *p = &a;
    printf("%p %d %p %f\n",p,*p,p2,*p2);
    printf("%llu %llu\n",sizeof(p),sizeof(p2));
    char a3[100];
    char *p3 = a3;
    scanf("%s",a3);
    printf("%llu %llu %llu %llu",sizeof(a3),sizeof(char),sizeof(p3),strlen(a3));
}