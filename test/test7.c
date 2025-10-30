#include<stdio.h>
int main(void){
    int  ac[]={0,1,2,3,4,5,6,7,8,9};
    int  *p = ac;
    printf("p = %p \n",p);
    printf("p+1 = %p \n",p+1);
}