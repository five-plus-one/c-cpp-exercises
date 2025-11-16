#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6+10;
struct qj{
    int x;int y;
}op[N];
int M,L;
bool comp(qj a,qj b){
    if(a.x==b.x) return a.y < b.y;
    else return a.x<b.x;
}
int main(){
    scanf("%d%d",&L,&M);
    for(int i=1;i<=M;i++){
        scanf("%d%d",&op[i].x,&op[i].y);
    }
    sort(op+1,op+M+1,comp);
    int x = op[1].x, y = op[1].y;
    int cnt = L+1;
    for(int i=2;i<=M;i++){
        if(op[i].x<=y){
            y = max(op[i].y,y);
        }else{
            cnt -= (y-x)+1;
            x = op[i].x;
            y = op[i].y;
        }
    }
    cnt -= (y-x)+1;
    printf("%d\n",cnt);
}