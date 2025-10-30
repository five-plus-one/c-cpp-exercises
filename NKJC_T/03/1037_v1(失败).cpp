#include<iostream>
using namespace std;
const int N = 1e5+10;
double dir[N],pos[N],time[N],timen;
int n,m;

bool finished(){
    bool flag = true;
    int i=1;
    while(dir[i]==1){
        i++;
    }
    for(;i<=m;i++){
        if(pos[i]==0){
            flag = false;
        }
    }
    return flag;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>dir[i]>>pos[i];
        time[i]=0;
    }
    while(finished()){
        for(int i=1;i<n;i++){
            if(dir[i]==1&&dir[i+1]==0){
                dir[i]=0;dir[i+1]=1;
                timen=(pos[i+1]-pos[i])/2;
                time[i]+=timen;
                time[i+1]+=timen;
                pos[i]+=timen;
                pos[i+1]-=timen;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dir[i]<<" "<<pos[i]<<" "<<timen<<endl;
    }
}