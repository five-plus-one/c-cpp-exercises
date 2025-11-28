#include<stdio.h>
#include<string.h>
int main(){
    char a[114] = {'1','1','4','5','1','4','\0','1','9','1','9'};
    // printf("%llu\n",sizeof("abc\0abc"));
    // printf("%llu\n",sizeof("abc\0"));
    // printf("%llu\n",sizeof("abc"));
    // printf("%llu\n",sizeof("abc\0\0"));
    // printf("%s %llu\n",a,sizeof(a));
    // printf("%llu %lld %lld\n",sizeof("a"),strlen("a"),strlen(a));
    printf("%d %d %d\n",strcmp("abc","abc\0d"),strcmp("x","abc"),strcmp("114","114"));
}