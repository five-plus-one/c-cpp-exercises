#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    cout<<"1 ";
    for(int i=3;i<=n;i+=2){ 
        cout<<i<<" "<<i-1<<" ";
    }
    if(n%2==0){
        cout<<n;
    }
}