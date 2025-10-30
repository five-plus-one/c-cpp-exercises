//TLE
#include<iostream>
using namespace std;

long long A,B,T,m,i;

long long getnum(long long n){
    if(n==1 || n==2){
        return 1;
    }else {
        return (A*getnum(n-1)+B*getnum(n-2));
    }
}

int main(){
    cin>>T>>A>>B;
    for(i=1;i<=T;i++){
        cin>>m;
        cout<<getnum(m) % 1000000007<<"\n";
    }
}