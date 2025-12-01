#include<iostream>
using namespace std;
using ll = long long;
ll cal(int n){
    if(n<10){
        return n;
    }else{
        ll cnt = 0;
        while(n){
            cnt+=n%10;
            n/=10;
        }
        return cal(cnt);
    }
}
int main(){
    ll n;
    cin>>n;
    cout<<cal(n);
}