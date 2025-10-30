#include<iostream>
#include<cmath>
using namespace std;

bool iszs(int n){
    bool iszs = true;
    if( n == 1){
        iszs = false;
    }else{
    for(int i=2;i<=sqrt(n);i++){
        if(n % i==0 && i<n && i>=2){
            iszs = false;
        }
    }}
    return iszs;
}
int T,n2;
int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n2;
        // cout<<iszs(n2)<<endl;
        if(iszs(n2)){
            cout<<"Yes";
        }else {
            cout<<"No";
        }
        cout<<endl;
    }
}