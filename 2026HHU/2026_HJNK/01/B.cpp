#include<iostream>
using namespace std;
using ll = long long;
const ll modnum = 998244353;
const int N = 2 * 1e5 + 10;
int a[N],b[N],n,T;
ll calandmod(int n){
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = ((ans%modnum) * (i % modnum))%modnum;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int b_min =  2*n;
        for(int i=1;i<=n;i++){
            cin>>b[i];
            b_min = min (b[i],b_min);
        }
        int n1=0,n2=0;
        for(int i=1;i<=n;i++){
            if(a[i] > b_min) n1++;
            else n2++;
        }
        ll ans = (calandmod(n1) % modnum) * (calandmod(n2) % modnum) % modnum;
        cout<<ans<<endl;
    }
}