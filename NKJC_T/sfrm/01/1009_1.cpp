#include<iostream>
using namespace std;
using ll = long long;
const int N =1e4+20;
int l,n,li,ri;
int delta[N]={0};
int main(){
    scanf("%d %d",&l,&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&li,&ri);
        if(li > ri) swap(li,ri);
        delta[li]++;
        delta[ri+1]--;
    }
    int cnt = 0,status = 0;
    for(int i=0;i<=l;i++){
        status+=delta[i];
        cnt+=(status==0);
    }
    printf("%d",cnt);
    return 0;
}