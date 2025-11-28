#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const ll N = 1e5+10;
struct st{
    ll t;
    ll d;
}cow[N];
ll dsum,n;
bool comp(st a,st b){
    return b.d*a.t<a.d*b.t;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dsum = 0;
    for(int i=1;i<=n;i++){
        cin>>cow[i].t>>cow[i].d;
        dsum += cow[i].d;
    }
    sort(cow+1,cow+1+n,comp);
    ll ans = 0;
    for(int i=1;i<=n;i++){
        dsum -=cow[i].d;
        ans += dsum * 2 * cow[i].t;
    }
    cout<<ans;
}