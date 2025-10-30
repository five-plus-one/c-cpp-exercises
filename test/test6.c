#include<stdio.h>
int main(void){
    int i=1;
    int *p = &i;
    printf("%p %d",p ,*p);
    return 0;
}