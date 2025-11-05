#include<stdio.h>
int sumnum(int a,int b){
    int cnt = 0;
    for(int i=a;i<=b;i++){
        cnt+=i;
    }
    return cnt;
}

int main(void){
    printf("%d\n%d\n%d\n",sumnum(1,10),sumnum(16,30),sumnum(40,60));
    return 0;
}