#include<iostream>
using namespace std;
using ll = long long;
ll A,B;
ll fakeejz(ll n){
    ll fakeejz = 0,tmp=1;
    while(n){
        fakeejz += tmp* ( n &1);
        n/=2;
        tmp*=10;
    }
    return fakeejz;
}
int main(){
    cin>>A>>B;
    cout<<fakeejz(A)+fakeejz(B);
}