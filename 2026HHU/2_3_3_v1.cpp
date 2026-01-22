// 20260122 5plus1 v1  二维差分
#include<iostream>
using namespace std;
const int N = 1e3 + 10;
int n,m,map[N][N],delta[N][N],x1,y1,x2,y2;
void carpet(int x1,int y1,int x2,int y2){
    delta[x1][y1] ++;
    delta[x1][y2+1]--;
    delta[x2+1][y1]--;
    delta[x2+1][y2+1]++;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    while(m--){
        cin>>x1>>y1>>x2>>y2;
        carpet(x1,y1,x2,y2);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j] = map[i-1][j] + map[i][j-1] - map[i-1][j-1] + delta[i][j];
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }
}