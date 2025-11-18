#include<iostream>
using namespace std;
int n,m; // n max 10,m max 100
int map[110],change[110],cur[110]; 
bool solve(int a[]){
    int cnt = 0;
    for(change[0] = 0;change[0]<(1<<n);change[0]++){
        for(int i=0;i<m;i++){
            cur[i] = map[i];
        }
        for(int i=1;i<m;i++){
            cur[i-1] = cur[i-1] ^ (change[i-1]) ^ (change[i-1]>>1) ^ ((change[i-1]<<1)&((1<<n)-1));
            cur[i] = cur[i] ^ (change[i-1]);
            change[i] = cur[i-1]; //为了让上一层全灭
        }
        cur[m-1] = cur[m-1] ^ (change[m-1]) ^ (change[m-1]>>1) ^ ((change[m-1]<<1)&((1<<n)-1));
        cnt+=(cur[m-1]==0);
    }
    return cnt>0;
}
int main(){
    scanf("%d%d",&n,&m);
    int innum;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&innum);
            map[j]|=(innum<<i);
        }
    }
    if(solve(map)){
        printf("YES");
    }else{
        printf("NO");
    }
}