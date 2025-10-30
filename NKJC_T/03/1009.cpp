#include<iostream>
using namespace std;
int cal(int n){
    return ((1+n)*n)/2;
}
int main(){
    int n,ans;
    cin>>n;
    for (int i =1;i<=n;i++){
        ans+=cal(i);
    }
    cout<<ans;
    return 0;
}