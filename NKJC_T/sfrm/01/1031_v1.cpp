//WA
#include<iostream>
using namespace std;
using ll = long long;
ll l,r,T;
ll getws(int n){
    if(n ==0 )return 0;
    int i=0;
    while((1LL<<i)<=n){
        i++;
    }
    return i;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>l>>r;
        ll ans = 0;
        if(l == r){
            ans = l;
        }else if(r == ((1LL<<getws(r))-1)){
            ans = r;
        }else if(getws(l)<getws(r)){
            ans = (1LL<<(getws(r)-1))-1;
        }else{
            ans = 0;
            // cout<<"-----"<<endl;
            for(int i= 62;i>=0;i--){
                // cout<<i<<"  "<<((l>>i)&1)<<" "<<((r>>i)&1)<<endl;
                if(((l>>i)&1)==((r>>i)&1)){
                    ans|= (((l>>i)&1)<<i);
                    // cout<<" "<<ans<<endl;
                }else{
                    ans |= ((1LL<<i)-1);
                    // cout<<" "<<ans<<endl;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}