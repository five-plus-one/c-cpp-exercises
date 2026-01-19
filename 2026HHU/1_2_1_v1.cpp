// 5plus1 2026/01/19
#include<iostream>
#include<cstdio>
using namespace std;
int a[1010],n,m=0,ai;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d",&ai);
        a[ai]++;
        if(a[ai] == 1) m++;
    }
    printf("%d\n",m);
    for(int i=1;i<=1000;i++){
        if(a[i]) printf("%d ",i);
    }
    printf("\n");
    return 0;
}