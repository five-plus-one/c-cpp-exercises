#include<iostream>
using namespace std;
int n,m,a[3010][3010],tl;
int calculate(int i,int j,int hp){
    if(i>1&&j>1){
        return hp+min(a[i-1][j],a[i][j-1]);
    }else if(i == 1){
        if(j==1){
            return hp;
        }else{
            return hp+a[1][j-1];
        }
    }else{
        if(j==1){
            return hp+a[i-1][1];
        }
    }
    return 0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&tl);
            a[i][j] = calculate(i,j,tl);
        }
    }
    printf("%d",a[n][m]);
}