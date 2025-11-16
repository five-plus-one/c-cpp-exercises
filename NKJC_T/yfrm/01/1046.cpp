#include<iostream>
using namespace std;
int main(){
    int a,b,n,maxnum,minnum;
    cin>>n>>a>>b;
    maxnum=min(a,b);
    if(a+b<=n){
        minnum=0;
    }else{
        minnum=a+b-n;
    }
    cout<<maxnum<<" "<<minnum;
    return 0;
}