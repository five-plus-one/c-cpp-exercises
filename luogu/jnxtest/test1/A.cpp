#include<iostream>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll a,ans = 0;
    for(int i=0;i<10;i++){
        cin >> a;
        ans += a;
    }
    cout<<ans;
    return 0;
}