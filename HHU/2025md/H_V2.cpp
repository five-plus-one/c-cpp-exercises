#include<iostream>
#include<unordered_map>
#include<vector>
using ll = long long;
using namespace std;
const int N = 2*1e5+10;
int ai;

int main(){
    ll T,x,n;
    scanf("%lld",&T);
    while(T--){
        unordered_map<int,int> mp;
        scanf("%lld %lld",&n,&x);
        vector<ll> qzh(n+10,0); //开的项数和初始化值
        mp[0]++; //非常重要
        for(int i=1;i<=n;i++){
            scanf("%d",&ai);
            qzh[i] = qzh[i-1]+ai;
            mp[qzh[i]%x]++;
        }
        unordered_map<int,int>::iterator it;
        ll cnt = 0;
        for(it = mp.begin();it!=mp.end();it++){
            cnt += it->second*(it->second-1)/2;
        }
        printf("%lld\n",cnt);
    }
    
    return 0;
}