#include<iostream>
using namespace std;
const int N = 1e5+10;
int n,b,pos,map[N],hzh[N],count[2*N],ai;
int main(){
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",&ai);
        if(ai==b){
            map[i] = 0;
            pos = i;
        }
        if(ai>b) map[i] = 1;
        if(ai<b) map[i] = -1;
    }
    hzh[pos] = 0;
    //向前求后缀和
    count[N] = 1; //标记pos位置（后缀和为0）的位置为1
    for(int i=pos-1;i>=1;i--){
        hzh[i]=hzh[i+1]+map[i];
        // cout<<i<<" "<<hzh[i]<<endl;
        count[N+hzh[i]]++;
    }
    int qzh = 0,cnt = 0;
    for(int i=pos;i<=n;i++){
        qzh+=map[i];
        cnt+=count[N-qzh];
    }
    printf("%d\n",cnt);
}