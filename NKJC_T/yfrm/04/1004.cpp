#include<iostream>
using namespace std;
const int N = 1e4+10;
int a[N],L,M,p,q;
int main(){
    cin>>L>>M;
    for(int i=1;i<=M;i++){
        cin>>p>>q;
        for(int j=p;j<=q;j++){
            a[j] = 1;
        }
    }
    int count =0;
    for(int i=0;i<=L;i++){
        count+=(a[i]==0);
    }
    cout<<count;
}