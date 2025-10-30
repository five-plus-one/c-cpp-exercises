#include<iostream>
using namespace std;
using ll = long long;
using ull = unsigned long long;
//快速幂算法
ll power(ll m,ll n){
    ll ans = 1;
    while(n){
        if(n&1){
            ans*=m;
        }
        m*=m;
        n >>= 1;
    }
    return ans;
}
//快速幂取余算法
ll powermod(ll m,ll n,ll p){
    ll ans = 1;
    while(n){
        if(n&1){
            ans = ans * m %p;
        }
        m=m*m%p;
        n>>=1;
    }
    return ans;
}
int main(){
    ll a,b,p;
    scanf("%lld %lld %lld",&a,&b,&p);
    printf("%lld\n%lld",power(a,b),powermod(a,b,p));
}