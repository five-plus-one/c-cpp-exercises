#include<iostream>
using namespace std;
using ll = long long;

int main(){
    int n,a;
    ll sumnum = 0;
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>a;
        sumnum += a;
    }
    ll ans = 0;
    while(sumnum){
        ans = ans * 10 + sumnum % 10;
        sumnum /= 10;
    }
    cout<<ans<<endl;


}