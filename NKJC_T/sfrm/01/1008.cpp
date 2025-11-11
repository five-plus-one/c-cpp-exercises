//差分
#include<iostream>
using namespace std;
using ll = long long;
const int N = 5* 1e5+20;
int ai,aib,cf[N],n,q,l,r,d;
int main(){
    cf[0] = 0;
    aib = 0;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&ai);
        cf[i] = ai-aib;
        aib = ai;
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d%d",&l,&r,&d);
        cf[l]+=d;
        cf[r+1]-=d;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans+=cf[i];
        printf("%lld ",ans);
    }
    return 0;
}