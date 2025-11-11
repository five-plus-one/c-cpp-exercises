#include<iostream>
using namespace std;
const long long N = 1e5+10;
long long A[N],n,Ai;

int calculateB(int m){
    if(m>=n){return 0;}
    // int returnnum = 0;
    for(int i=m+1;i<=n;i++){
        if(A[i]>A[m]){
            return i;
        }
    }
    return 0;
}
int main(){
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>A[i];
    }
    for(long long i=1;i<=n;i++){
        cout<<calculateB(i);
        if(i<n){cout<<" ";}
    }
}