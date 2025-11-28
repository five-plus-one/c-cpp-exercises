#include<iostream>
using namespace std;
using ll = long long;
ll l,r;
int T;
ll deal(ll l,ll r){
    if(l == r){
        return 0;
    }
    ll l2=0,r2=0;
    for(int i= 62;i>=0;i--){
        if( ((l>>i)&1) == ((r>>i)&1)){
            l2 |= (((l>>i)&1)<<i);
            r2 |= (((l>>i)&1)<<i);
        }else{
            l2 |= ((1LL<<i)-1);
            r2 |= ((1LL<<i));
            break;
        }
    }
    return l2 ^ r2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>l>>r;
        cout<<deal(l,r)<<endl;
    }
}