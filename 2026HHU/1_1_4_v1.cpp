// 5plus1 2026/01/19
#include<iostream>
using namespace std;
int n;
int a[41][41];
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            a[i][j] = -1;
        }
    }
    int x = 1,y=(n+1)/2;
    a[x][y] = 1;
    for(int k=2;k<=n*n;k++){
        if(x == 1 && y<n){
            x = n;y++;
        }else if(y==n && x>1){
            x--;y=1;
        }else if(x == 1 && y==n){
            x++;
        }else if(a[x-1][y+1] == -1){
            x--;y++;
        }else{
            x++;
        }
        a[x][y] = k;
        // cout<<x<<" "<<y<<" "<<k<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}