#include<iostream>
#include<cstdio>
using namespace std;
const int N = 1010;
int map[N][N]={},n,m,xi,yi;
const int scanx[]={-1,0,0,1},
          scany[]={0,1,-1,0};
bool change = false;
int getinfectnum(int x,int y){
    if(map[x][y] == 1){return 1;}
    int cnt = 0;
    for(int i=0;i<4;i++){
        if(map[x+scanx[i]][y+scany[i]] == 1){
            cnt ++;
        }
    }
    if(cnt >=2){
        return 1;
        // cout<<x<<y<<endl;
        change = true;
    }else{
        return 0;
    }
}
bool allinfected(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]!=1){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++){
        scanf("%d%d",&xi,&yi);
        map[xi][yi] = 1;
    }
    
    change = true;
    while(change){
        change = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                map[i][j] = getinfectnum(i,j);
            }
        }
    }
    if(allinfected()){
        printf("YES");
    }else{
        printf("NO");
    }
    //
    // cout<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //

}