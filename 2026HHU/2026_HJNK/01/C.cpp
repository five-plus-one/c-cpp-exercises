#include<iostream>
using namespace std;
using ll = long long;
ll T,a,a_max,n,a_1,a_n;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>n;
        a_max = 0;
        for(int i=1;i<=n;i++){
            cin>>a;
            if(i == 1) a_1 = a;
            if(i == n) a_n = a;
            a_max = max(a,a_max);
        }

        cout<<a_max * n - (a_max - a_1) - (a_max - a_n)<<endl;
    }
}