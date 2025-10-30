#include<iostream>
#include<cstdio>
using namespace std;
long long n,T,centernum,num,sumnum;
int main(){
    scanf("%lld",&T);
    for(int i=1;i<=T;i++){
        scanf("%lld",&n);
        centernum = (n/2)*n+(n/2)+1;
        num = ((n-1)*(n-1))/2 + n;
        sumnum = centernum * num;
        printf("%lld\n",sumnum);
    }
    return 0;
}