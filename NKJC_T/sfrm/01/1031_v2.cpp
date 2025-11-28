#include<iostream>
using namespace std;
using ll = long long;
ll T,l,r;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>l>>r;
        if(l == r){
            cout<<l<<endl;
            continue;
        }
        ll i = 1;
        while( (((1LL<<i)-1) | l) <=r){
            i++;
        }
        cout<<(((1LL<<(i-1))-1) | l )<<endl;
    }
}