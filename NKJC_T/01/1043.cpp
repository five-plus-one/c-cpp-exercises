#include<iostream>
using namespace std;
int main(){
    int n,ans;cin>>n;
    if(n%3==0){
        ans = n/3 *2;
    }else{
        ans = n/3 *2 +1;
    }
    cout<<ans;
    return 0;
}