//不完善，没发全部AC
#include<iostream>
using namespace std;
const long long modnum = 998244353;
long long a,b,c,ans=0,i,j,k;
int main(){
    cin>>a>>b>>c;
    for(i=1;i<=a;i++){
        for (j=1;j<=b;j++){
            for(k=1;k<=c;k++){
                ans+=(i*i*i*j*j*(c-k));
            }
        }
    }
    ans = ans % modnum;
    cout<<ans;
}