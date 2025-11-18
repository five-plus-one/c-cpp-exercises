#include<iostream>
using namespace std;
using ll = long long;
int main(){
    ll cnt = 0;
    int xh,n;
    scanf("%d",&n);
    cnt = (ll)n*(n+1)/2;
    for(int i=1;i<=n-1;i++){
        scanf("%d",&xh);
        cnt-=xh;
    }
    printf("%lld",cnt);
}