#include<stdio.h>
int main(){
    char a[114] = {'1','1','4','5','1','4','\0','1','9','1','9'};
    printf("%d\n",sizeof("abc\0abc"));
    printf("%d\n",sizeof("abc\0"));
    printf("%d\n",sizeof("abc"));
    printf("%d\n",sizeof("abc\0\0"));
    printf("%s %d\n",a,sizeof(a));
}