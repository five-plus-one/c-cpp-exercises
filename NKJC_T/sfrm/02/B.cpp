#include<iostream>
using namespace std;
using ll = long long;
ll f(ll n){
    if(n==0) return 0;
    if(n==1) return 1;
    return f(n/2)+f(n%2);
}
int main(){
    ll T,n;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        printf("%lld %lld\n",f(n),((1LL<<f(n))-1));
    }
}