//AC
#include<iostream>
using namespace std;
const long long N = 1e6+10;
int count[N],last[N],n,m,ni;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&ni);
        count[ni]++;last[ni]=i;
    }
    for(int i=1;i<=n;i++){
        if(count[i]==0){printf("-1 ");}else{
        printf("%d ",count[i]);}
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        if(last[i]==0){printf("-1 ");}else{
        printf("%d ",last[i]);}
    }
    return 0;
}