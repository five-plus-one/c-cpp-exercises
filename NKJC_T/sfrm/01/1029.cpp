#include<iostream>
#include<algorithm>
using ll = long long;
using namespace std;
const int N = 1e3+10;
ll n;
struct st{
    ll left;
    ll right;
}person[N];
bool comp(st a,st b){
    return max(a.left/a.right,a.left*b.left/b.right)<max(b.left/b.right,a.left*b.left/a.right);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>person[i].left>>person[i].right;
    }
    sort(person+1,person+1+n,comp);
    ll ans = 0,cj = 1;
    for(int i=1;i<=n;i++){
        cj *= person[i-1].left;
        ans = max(ans,cj/person[i].right);
    }
    cout<<ans;
}