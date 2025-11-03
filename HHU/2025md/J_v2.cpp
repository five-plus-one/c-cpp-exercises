#include<iostream>
using namespace std;
using ll = long long;
int main(){
    ll T,N;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&N);
        ll ds = 1,ans = 0;
        while(ds<=N){
            ans+=N/ds;
            ds*=2;
        }
        printf("%lld\n",ans);
    }
}