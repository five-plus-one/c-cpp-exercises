//这是错误答案

#include<iostream>
using namespace std;
int map[101][101],m,n,total,i,j,p,q;
int main(){
    cin>>n>>m>>total;
    for(i=0;i<total;i++){
        cin>>p>>q;
        map[p][q]=-1;
        if(p>1 && map[p-1][q]!= -1){
            map[p-1][q]++;
        }
        if(p<n && map[p+1][q]!= -1){
            map[p+1][q]++;
        }
        if(q>1 && map[p][q-1]!=-1){
            map[p][q-1]++;
        }
        if(q<m && map[p][q+1]!=-1){
            map[p][q+1]++;
        }
        if(p>1 && q>1 && map[p-1][q-1]!= -1){
            map[p-1][q-1]++;
        }
        if(p>1 && q<m && map[p-1][q+1]!= -1){
            map[p-1][q+1]++;
        }
        if(p<n && q>1 && map[p+1][q-1]!= -1){
            map[p+1][q-1]++;
        }
        if(p>1 && q<m && map[p+1][q+1]!= -1){
            map[p+1][q+1]++;
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