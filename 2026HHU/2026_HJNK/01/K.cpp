#include<iostream>
using namespace std;
int T,n;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        if(n == 1){
            cout<<"YES\n1\n";
        }else if(n==3){
            cout<<"YES\n1 2 3\n";
        }else{
            cout<<"NO\n";
        }
    }
}