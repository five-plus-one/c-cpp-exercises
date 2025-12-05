#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2*1e5+10;
long long n,m,k,a[N];
bool comp(long long a,long long b){
    return a>b;
}
int main(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n,comp);
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        if(a[i]+m>=k){
            ans++;
            m-=(k-a[i]);
        }else{
            break;
        }
    }
    printf("%lld",ans);
}