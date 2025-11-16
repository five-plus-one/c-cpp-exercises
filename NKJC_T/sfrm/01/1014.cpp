#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2*1e5+10;
int map[N],a[N],n;
struct lr{
    int l;int r;int len;
}ans[N];
int cnt;
bool comp(lr a,lr b){
    if(a.len<b.len) return 0;
    if(a.len>b.len) return 1;
    if(a.l<b.l) return 1;
    if(a.l>b.l) return 0;
    return a.r<b.r;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    map[a[1]]=1;
    cnt = 0;
    for(int l=1,r=1;l<=n;l++){
        bool flag = true;
        while(r<=n && flag){
            r++;
            if(map[a[r]]>0){
                flag = false; //此时的r为第一个不满足的
            }else{
                map[a[r]]++;
            }
        }
        r--; //此时的r为满足题意的
        cnt++;
        ans[cnt].l = l;ans[cnt].r = r; ans[cnt].len = r-l+1;
        //因为接下来l会自增，所以排除掉l
        map[a[l]]--;
    }
    sort(ans+1,ans+1+cnt,comp);
    int solvenum = 1,solvelen = ans[1].len;
    while(ans[solvenum].len==solvelen){
        solvenum++;
    }
    solvenum --;
    printf("%d\n",solvenum);
    for(int i=1;i<=solvenum;i++){
        printf("%d %d\n",ans[i].l,ans[i].r);
    }

}