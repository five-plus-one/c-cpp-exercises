#include<iostream>
using namespace std;
const long long N = 998244353;
int main(){
    long long a,b,c,cnt = 0;
    scanf("%lld %lld %lld",&a,&b,&c);
    for(long long i=1;i<=a;i++){
        cnt+= (b%N)*((b+1)%N)*((2*b+1)%N)/6*((c%N)*((c-1)%N)/2) * (i%N)*(i%N)*(i%N) ;
    }

    cnt = cnt %N;
    printf("%lld",cnt);
    return 0;
}