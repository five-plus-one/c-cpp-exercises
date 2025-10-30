#include<iostream>
using namespace std;
const int N = 110;
int map[N][N]={0},n,m,T,x,y;
int scanX[] = {-1,-1,-1,0,0,1,1,1},
    scanY[] = {0,1,-1,1,-1,1,0,-1};
int cal(int x,int y){
    if(map[x][y] == -1){
        return -1;
    }
    int cnt = 0;
    for(int i=0;i<8;i++){
        cnt += map[x+scanX[i]][y+scanY[i]]==-1;
    }
    return cnt;
}
void printmap(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=T;i++){
        scanf("%d%d",&x,&y);
        map[x][y] = -1;
    }
    // printmap();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            map[i][j] = cal(i,j);
        }
    }
    printmap();
    
}