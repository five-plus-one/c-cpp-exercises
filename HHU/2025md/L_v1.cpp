#include<iostream>
#include<unordered_set>
using namespace std;
using ll = long long;
const ll N = 1e6+10;
ll a[N],n,k;
int main(){
    scanf("%lld%lld",&n,&k);
    for(ll i =1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    //左区间遍历
    ll ans=0;
    for(ll left = 1; left<=n;left++){
        unordered_set<ll> s;
        for(ll right = left;right<=n;right++){
            if(s.count(k-a[right])){
                ans+=n-right+1;
                break;
            }
            s.insert(a[right]);
        }
    }
    printf("%lld\n",ans);
}