// @5plus1 2026/01/19
#include<iostream>
using namespace std;
using ll = long long;
ll ksm(ll a,ll b,ll p){
    ll res = 1;
    a %=p;
    while(b){
        if(b & 1) res = (res * a) %p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main(){
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<a<<'^'<<b<<" mod "<<p<<'='<<ksm(a,b,p)<<endl;
}