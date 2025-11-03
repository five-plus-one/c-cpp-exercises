#include<iostream>
using namespace std;
using ll = long long;
int main(){
    ll T,n;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        ll zcs = 1,power = 1,cnt=0,cs=1,remain=n-1;
        while(zcs<=n){
            cnt+=power*cs;
            remain = n-zcs;
            power*=2;
            zcs+=power;
            cs++;
        }
        cnt+=cs*remain;
        printf("%lld\n",cnt);
    }
}