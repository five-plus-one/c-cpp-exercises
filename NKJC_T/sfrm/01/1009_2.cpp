#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e3;
int l,n,cnt;
struct lr{
    int x,y;
}a[N];
bool comp(lr a,lr b){
    if(a.x<b.x) return 1;
    else return 0;
}
int main(){
    scanf("%d %d",&l,&n);
    cnt = l+1;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a+1,a+n+1,comp);
    int x = a[1].x,y=a[1].y;
    for(int i=2;i<=n;i++){
        if(a[i].x<=y){ // 可以合并
            y = max(a[i].y,y); //更新新的右边界
        }else{ //不能合并
            cnt -= (y-x+1); //移除[x,y]
            x = a[i].x;
            y = a[i].y;
        }
    }
    cnt -= (y-x+1); //移除[x,y]
    printf("%d",cnt);
}