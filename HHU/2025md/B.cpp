#include<iostream>
using namespace std;
int cal(long long n){
    return((n%2==0)+(n%3==0)+(n%5==0)+(n%7==0));
}
int main(){
    long long l,r,cnt=0;
    scanf("%lld %lld",&l,&r);
    for(long long i=l;i<=r;i++){
        cnt+=(cal(i)==2);
    }
    printf("%lld",cnt);
    return 0;
}