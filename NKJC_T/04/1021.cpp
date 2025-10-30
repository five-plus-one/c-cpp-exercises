#include<iostream>
#include<cstdio>
using namespace std;
const int N = 20;
int map[N][N];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",map[j][i]);
        }
        printf("\n");
    }
    return 0;
}