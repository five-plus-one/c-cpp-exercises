//bfs板子题
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

bool denied[11][9];
int dist[11][9];
int dx[] = {0,0,1,-1},
    dy[] = {1,-1,0,0};

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
    int xc,yc,px,py,rx,ry;
    cin>>xc>>yc>>px>>py>>rx>>ry;
    memset(denied,0,sizeof(denied));
    for(int x = xc;x <= xc + 3;x ++ ){
        for(int y = yc-2; y <= yc; y++){
            denied[x][y] = 1;
        }
    }

    denied[rx][ry] = 1; 


    // for(int x=0;x<=10;x++)
    //     for(int y=0;y<=8;y++)
    //     if(denied[x][y])
    //         cout << "(" << x << "," << y << ")" << endl;

    
    memset(dist,-1,sizeof(dist));
    dist[10][8] = 1;
    queue<pair<int,int>> q;
    q.push({10,8});
    while(!q.empty()){
        auto [cx,cy] = q.front(); q.pop();
        if(cx == px && cy == py){ //到达
            cout<<dist[cx][cy] << endl; //包含起点终点
            return 0;
        }

        for(int dir = 0;dir < 4;dir ++){
            int nx = cx + dx[dir], ny = cy + dy[dir];
            if(nx < 0 || nx > 10 || ny < 0 || ny > 8) continue; //越界了
            if(denied[nx][ny]) continue; //不允许走
            if(dist[nx][ny] != -1) continue; //已访问
            dist[nx][ny] = dist[cx][cy] + 1;
            // cout << "Visiting: (" << nx << "," << ny << ") with distance " << dist[nx][ny] << endl;
            q.push({nx,ny});
        }
    }
    //无法到达
    cout<< -1 <<endl;
    return 0;
}