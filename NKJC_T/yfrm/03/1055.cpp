#include<iostream>
using namespace std;

int gys(long long m,long long n){
    if(m==n){
        return m;
    }else if(m>n){
        return gys(m-n,n);
    }else{
        return gys(m,n-m);
    }
}
int main(){
    long long m,n;
    cin>>m>>n;
    cout<<gys(m,n);
    return 0;
}