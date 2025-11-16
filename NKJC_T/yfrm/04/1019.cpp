#include<iostream>
using namespace std;
const int N = 1010;
const int scanx[8] = {-1,-1,-1,0,0,1,1,1};
const int scany[8] = {1,0,-1,1,-1,1,0,-1};
char map[N][N];
int n,m;
char callei(int n,int m){
    if(map[n][m] == '*'){
        // cout<<endl<<n<<" "<<m<<endl;
        return '*';
    }
    int cnt = 0;
    for(int i=0;i<8;i++){
        if(map[n+scanx[i]][m+scany[i]] == '*'){
            cnt ++;
        }
    }
    return '0'+cnt;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&map[i][j]); //加一个空格防止把空格输入
            // cout<<i<<j<<" "<<map[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            map[i][j] = callei(i,j);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}