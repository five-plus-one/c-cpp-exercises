#include<iostream>
using namespace std;
int a[6][6],n,m,x,y;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d%d",&x,&y);
    printf("%d",a[x][y]);
}