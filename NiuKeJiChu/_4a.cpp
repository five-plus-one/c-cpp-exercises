#include<iostream>
using namespace std;
int main(){
    long long n,ans =0;
    long long tmp = 1;
    cin>>n;
    while(n){
        ans +=tmp * (n & 1);
        n >>=1;
        tmp *=10;
    }
    cout<<ans;
}