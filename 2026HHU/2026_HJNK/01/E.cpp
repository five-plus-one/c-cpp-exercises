#include<iostream>
using namespace std;
const int N = 2 * 1e5 +10;
int n,k,a[N],T;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n>>k;
        a[0] = k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int maxnum = a[0] + a[n];
        for(int i=0;i<n;i++){
            maxnum = max(maxnum,a[i]+a[i+1]);
        }
        cout<<maxnum<<endl;
    }
}