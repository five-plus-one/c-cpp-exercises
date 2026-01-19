// @5plus1 2026/01/19 v1
#include<iostream>
#include<string>
using namespace std;
const int N = 1e5 +10;
struct st{
    int pos;
    string name;
}person[N];
int n,m,pos = 0,ai,si;
void next(int dir,int len){ // 1逆时针 -1顺时针
    len = len % n;
    pos += len * dir;
    if(pos >= n) pos -=n;
    if(pos < 0) pos +=n;
    return;
}
int getdir(int to,int lr){
    if(to^lr) return 1;
    else return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>person[i].pos>>person[i].name;
    }
    pos = 0;
    for(int i=0;i<m;i++){
        cin>>ai>>si;
        next(getdir(person[pos].pos,ai),si);
    }
    cout<<person[pos].name<<endl;
    return 0;
}
