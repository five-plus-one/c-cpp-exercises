// 5plus1 2026/01/19 v2
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[110],n,m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    m = unique(a+1,a+n+1) - (a+1);
    printf("%d\n",m);
    for(int i=1;i<=m;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}