#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 1e5+10;
ll n;
struct st {
    ll c;
    ll d;
}activity[N];
bool comp(st a,st b){
    return a.d<b.d;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>activity[i].c>>activity[i].d;
    }
    sort(activity+1,activity+1+n,comp);
    ll maxtime = 0,timestamp = 0,currenttime = 0;
    for(int i=1;i<=n;i++){
        timestamp+=activity[i].c;
        if(timestamp > activity[i].d){
            currenttime = timestamp - activity[i].d;
            maxtime = max(maxtime,currenttime);
        }
    }
    cout<<maxtime;
    return 0;
}