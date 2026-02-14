//5plus1 20260129
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
using ll = long long;
int tree[N],n,h,lefth,righth,ans;
ll m;
bool judge(int h){
    ll len = 0;
    for(int i=1;i<=n;i++){
        if(tree[i] > h) len+= tree[i] - h;
    }
    return len >= m;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    lefth = righth = 0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>tree[i];
        righth = max(righth,tree[i]);
    }
    while(lefth <= righth){
        int midh = lefth + (righth - lefth )/2;
        if(judge(midh)){
            lefth = midh +1;
            ans = midh;
        }
        else righth = midh -1;
    }
    cout<<ans<<endl;;
}