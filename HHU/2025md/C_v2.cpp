#include<iostream>
using namespace std;
using ll = long long;
const ll N = 998244353;
ll powermod(ll a,ll b,ll p){
    ll ans = 1;
    while(b){
        if(b&1){
            ans=ans*a%p;
        }
        a = a*a%p;
        b>>=1;
    }
    return ans;
}

ll calA(ll a){
    return a%N*(a+1)%N*a%N*(a+1)%N*(powermod(4,N-2,N))%N;
}
ll calB(ll b){
    return b%N*(b+1)%N*(2*b+1)%N*(powermod(6,N-2,N))%N;
}
ll calC(ll c){
    return c%N*(c-1)%N*(powermod(2,N-2,N))%N;
}
int main(){
    ll a,b,c,cnt = 0;
    scanf("%lld %lld %lld",&a,&b,&c);
    cnt = calA(a)%N*calB(b)%N*calC(c)%N;
    printf("%lld",cnt);
    return 0;
}