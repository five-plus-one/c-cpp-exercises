#include<iostream>
using namespace std;
int main(){
    int i=0,n,num=0,ws=1,xh=9;
    scanf("%d",&n);
    while(i<n){
        for(int j=1;j<=xh;j++){
            i+=ws;
            num++;
            if(i>=n){
                break;
            }
        }
        if(i<n){
            ws++;
            xh*=10;
        }
    }
    for(int j=1;j<=i-n;j++){
        num/=10;
    }
    int ans = num%10;
    cout<<ans;
}