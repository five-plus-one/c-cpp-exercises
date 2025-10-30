//40TLE
#include<iostream>
using namespace std;
long long cal0(long long n){
    long long cnt = 0;
    while((n&1) == 0){
        n=n>>1;
        cnt++;
    }
    return cnt;
}
int main(){
    long long T,N;
    scanf("%lld",&T);
    while(T--){
        long long ans = 0;
        scanf("%lld",&N);
        for(long long i=1;i<=N;i++){
            ans+=cal0(i);
        }
        ans+=N;
        printf("%lld\n",ans);
    }
}