#include<stdio.h>
int main(){
    char s[] = "ab",*p;
    p = s;
    printf("%c",*(p+2));
}