#include<iostream>
#include<bitset>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
const int N = 3010;
const int N2 = N*(N-1)/2;
struct point{
    int x;int y;
}p[N];
struct line{
    int a;int b;int dis2;
}l[N2];
int caldis2(int a,int b){
    return (p[a].x-p[b].x)*(p[a].x-p[b].x) + (p[a].y-p[b].y)*(p[a].y-p[b].y);
}
bool comp(line a,line b){
    return a.dis2 > b.dis2;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    int m =0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            l[++m].a = i;
            l[m].b = j;
            l[m].dis2 = caldis2(i,j); 
        }
    }
    sort(l+1,l+1+m,comp);
    bitset<N> map[N];
    double r;
    for(int i=1;i<=m;i++){
        //先检查这两个点有没有被连到一个点
        //两个点的id分别为l[i].a l[i].b
        if((map[l[i].a] & map[l[i].b]) != 0){ // 有公共点
            r = sqrt(l[i].dis2) / 2;
            break;
        }else{
            map[l[i].a][l[i].b] = 1;
            map[l[i].b][l[i].a] = 1;
        }
    }
    cout << fixed << setprecision(10) << r << endl;
}