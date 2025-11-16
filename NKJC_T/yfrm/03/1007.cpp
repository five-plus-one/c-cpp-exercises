#include<iostream>
using namespace std;
int main(){
    double n,ans=0;
    cin>>n;
    for(double i=1;i<=n;i++){
        ans += 1/i;
    }
    cout<<ans;
    return 0;
}