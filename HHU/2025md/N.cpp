#include<iostream>
using namespace std;
using ll = long long;
const int N = 120;
int map[N][N]={0},n,m,globalx,globaly;
const int scanX[]={-1,0,0,1,0};
const int scanY[]={0,1,-1,0,0};
int get1num(){
    globalx = -1;
    globaly = -1;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt+=(map[i][j]==1);
            if(map[i][j]==1&&globalx == -1&&globaly ==-1){
                globalx = i;globaly = j;
            }
        }
    }
    return cnt;
}
void getfirst1pos(){
    globalx = -1;globaly = -1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j]==1){
                globalx = i;globaly = j;
                return;
            }
        }
    }
    return;
}
// 感染
void gr(int x,int y){
    if(x<=0||y<=0){
        return;
    }
    map[x][y]=2;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int xpos = x+scanX[i]+scanX[j];
            int ypos = y+scanY[i]+scanY[j];
            if(xpos>0&&ypos>0){
                if(map[xpos][ypos]==1){
                    gr(xpos,ypos);
                }
            }
        }
    }
}
void printmap(){
    printf("----\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d",map[i][j]);
        }
        printf("\n");
    }
    printf("----\n");
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    int ans = 0;
    // cout<<n<<endl<<m<<endl<<get1num()<<endl;
    // printmap();
    while(get1num()){
        ans++;
        gr(globalx,globaly);
        // printmap();
    }
    printf("%d\n",ans);
    return 0;
}