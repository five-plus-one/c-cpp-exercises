#include<iostream>
using namespace std;
const int N = 510;
int map[N][N];
int T,n,q,op,k,v;
void initmap(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j] = 0;
        }
    }
    return ;
}
void fillf(int op,int k,int v){
    for(int i=1;i<=n;i++){
        if(op == 1){
            map[k][i] = v;
        }else if(op ==2){
            map[i][k] = v;
        }
    }
}
int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d%d",&n,&q);
        initmap(n);
        for(int j=1;j<=q;j++){
            scanf("%d%d%d",&op,&k,&v);
            fillf(op,k,v);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%d ",map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}