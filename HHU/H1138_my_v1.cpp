//30 Time Exceeded
#include<iostream>
using namespace std;
const long long N = 1e6+10;
int count[N],last[N],n,m,ni;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>ni;
        count[ni]++;last[ni]=i;
    }
    for(int i=1;i<=n;i++){
        if(count[i]==0){cout<<"-1";}else{
        cout<<count[i];}
        if(i<n){cout<<" ";}
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        if(last[i]==0){cout<<"-1";}else{
        cout<<last[i];}
        if(i<n){cout<<" ";}
    }
    return 0;
}