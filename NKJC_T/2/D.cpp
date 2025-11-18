#include<iostream>
#include<cstdio>
using namespace std;
using ll = long long;
int n,k,m;
const int N =1e6+10;
int map[N];
int main(){
    scanf("%d%d",&n,&k);
    m=-1;
    int num,lastnum = -1,numcnt = 0;
    for(int i=1;i<=n;i++){
        scanf("%1d",&num);
        if(num!=lastnum){
            map[++m] = numcnt;
            numcnt = 1;
            lastnum = num;
        }else{
            numcnt++;
        }
    }
    map[++m] = numcnt;
    // for(int i=1;i<=m;i++){
    //     cout<<map[i]<<endl;
    // }
    ll ans = 0;
    if(k==1){
        for(int i=1;i<=m;i++){
            ans+=((map[i]+1)*map[i]/2);
        }
    }else{
        for(int i=1;i<=m-k+1;i++){
            ans+=(map[i]*map[i+k-1]);
        }
    }
    printf("%lld",ans); 
    return 0;
}