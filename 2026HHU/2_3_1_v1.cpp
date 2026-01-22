// 5plus1 20260122 v1
#include<iostream>
using namespace std;
const int N = 1e5+10;
int a[N],qzh[N],n,m,l,r;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    qzh[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        qzh[i] = qzh[i-1] + a[i];
    }
    cin>>m;
    while(m--){
        cin>>l>>r;
        cout<<qzh[r]-qzh[l-1]<<endl;
    }
    return 0;
}