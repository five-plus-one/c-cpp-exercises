//思想：蚂蚁等效，所以可以理解为交换，即不换方向直接走
#include<iostream>
using namespace std;
int n,m,maxtime=0,dir,pos,timen;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>dir>>pos;
        if(dir == 1){
            timen = n-pos;
        }else {
            timen = pos;
        }
        if(timen>maxtime){
            maxtime=timen;
        }
    }
    cout<<maxtime;
}