// 20260122 5plus1
#include<iostream>
using namespace std;
using ll = long long;
const int N = 1e3+10;
int n,m,c,x,y,max_x,max_y,map[N][N];
ll qzh[N][N],value,max_value;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>c;
    max_value = -32767 *n*m -1;
    for(x = 1;x<=n;x++){
        for(y=1;y<=m;y++){
            cin>>map[x][y];
            qzh[x][y] = qzh[x-1][y] + qzh[x][y-1] - qzh[x-1][y-1] + map[x][y];
        }
    }
    for(int x=1; x<=n-c+1;x++){
        for(int y=1;y<=m-c+1;y++){
            int x1 = x-1,y1 = y-1,
                x2 = x+c-1,y2 = y+c-1;
            value = qzh[x2][y2] - qzh[x1][y2] - qzh[x2][y1] + qzh[x1][y1];
            if(value > max_value){
                max_value = value;
                max_x = x;
                max_y = y;
            }
        }
    }
    cout<<max_x<<' '<<max_y<<endl;
    return 0;
}