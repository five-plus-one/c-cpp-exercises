#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;
const int N = 2e5+10;
struct lr{
    int pos;int num;
}delta[N];
int l,n,li,ri;
bool comp(lr a,lr b){
    if(a.pos == b.pos) return a.num<b.num;
    else return a.pos<b.pos;
}
int main(){
    scanf("%d %d",&l,&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&li,&ri);
        delta[i].pos = li;
        delta[i].num = 1;
        delta[i+n].pos = ri+1;
        delta[i+n].num = -1;
    }
    sort(delta+1,delta+2*n+1,comp);
    int status = 0,ans = 0;
    for(int i=1;i<=2*n;i++){
        status += delta[i].num;
        if(status ==1 && delta[i].num ==1){
            ans+= delta[i].pos - delta[i-1].pos; //从 i-1 pos到 (i pos)-1
        }
    }
    ans += l - delta[2*n].pos +1;
    printf("%d\n",ans);
    return 0;
}