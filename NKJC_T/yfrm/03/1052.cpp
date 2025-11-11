#include<iostream>
using namespace std;
int s,m,n;
int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            cin>>s;
            if(s==1){
                m=i;n=j;
            }
        }
    }
    cout<<abs(m-3)+abs(n-3);
}