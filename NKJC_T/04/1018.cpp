#include<iostream>
using namespace std;
int n;
int a[11][11];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    bool flag = true;
    if(n == 1){
        if(a[1][1]==0){
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
        return 0;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(a[i][j]!=0){
                flag = false;
            }
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }else {
        cout<<"NO"<<endl;
    }
}