#include<iostream>
#include<cmath>
using namespace std;
bool iszs(long long n){
    if(n==1){
        return false;
    }
    long long i=2;
    bool flag = true;
    for(;i<=sqrt(n);i++){
        if(n%i==0 && i<n){
            flag = false;
            break;
        }
    }
    return flag;
}
int main(){
    long long l,r;
    cin>>l>>r;
    for(long long i=l;i<=r;i++){
        if(iszs(i)){
            printf("%lld\n",i);
        }
    }
}