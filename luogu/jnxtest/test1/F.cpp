#include<iostream>
#include<algorithm>
using namespace std;
const int N = 35;
int n,map[N][N],x,y,cnt = 0;
struct choice{
    int type; //1 行，0 列
    int sumnum;
    int id;
} choices[2*N];

bool comp(choice a,choice b){
    if (a.sumnum != b.sumnum) 
        return a.sumnum > b.sumnum; // 优先稻草之和最大的
    if (a.type != b.type) 
        return a.type > b.type;     // 和相同时，优先行
    return a.id < b.id;             // 类别也相同时，编号小的优先
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++){
        int tmpsum = 0;
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            tmpsum += map[i][j];
        }
        choices[i].type = 1;
        choices[i].sumnum = tmpsum;
        choices[i].id = i;
    }
    for(int i=1;i<=n;i++){
        int tmpsum = 0;
        for(int j=1;j<=n;j++){
            tmpsum += map[j][i];
        }
        choices[i+n].type = 0;
        choices[i+n].sumnum = tmpsum;
        choices[i+n].id = i;
    }
    while(map[x][y] > 0){
        cnt ++;
        sort(choices+1,choices+1+2*n,comp); //数据量不大，懒得优化了直接排序
        choices[1].sumnum -= min(choices[1].sumnum,n);
        if(choices[1].type == 1){ //行
            for(int i=1;i<=n;i++){
                map[choices[1].id][i] = max(0,map[choices[1].id][i]-1);
            }
            
        }else{ //列
            for(int i=1;i<=n;i++){
                map[i][choices[1].id] = max(0,map[i][choices[1].id]-1);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}