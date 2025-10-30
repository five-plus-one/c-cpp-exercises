#include<iostream>
using namespace std;
int n;
int map[25][25];
const int dirX[]={0,1,0,-1},
          dirY[]={1,0,-1,0};
int x=1,y=1,dir = 0,num = 1;

void nextstep(){
    x+=dirX[dir];
    y+=dirY[dir];
}
bool needtochangedir(){
    int xtmp = x+dirX[dir];
    int ytmp = y+dirY[dir];
    if(xtmp>n||ytmp>n||xtmp<1||ytmp<1){return true;}
    if(map[xtmp][ytmp] > 0){return true;}
    return false;
}
void changedir(){
    dir++;
    if(dir>3){dir = 0;}
}
int main(){
    scanf("%d",&n);
    x=1;y=1;
    
    for(int i=1;i<=n*n;i++){
        map[x][y] = i;
        if(needtochangedir()){changedir();}
        nextstep();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}