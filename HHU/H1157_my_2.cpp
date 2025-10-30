#include<iostream>
using namespace std;
const int N = 110;
int n,m,T,i,j,map[N][N],
    dx[]={-1,-1,-1,0,0,1,1,1},
    dy[]={1,0,-1,1,-1,1,0,-1};
bool can(int x,int y){
    return ( x>0 && x<=n && y>0 && y<=m && map[x][y]!=-1);
}



int main(){
    cin>>n>>m>>T;

    for(int k=1;k<=T;k++){
        cin>>i>>j;
        map[i][j]=-1;

    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(map[i][j]==-1){
                for(int l=0;l<8;l++){
                    if(can(i+dx[l],j+dy[l])){
                        map[i+dx[l]][j+dy[l]]++;
                    }
                }
            }   
        }
       
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cout<<map[i][j];
            if(j<m){
            cout<<" ";
            }
        }
        if(i<n){
            cout<<endl;
        }
        
    }

}