//P1019 好题https://ac.nowcoder.com/acm/contest/19305/1019

#include<iostream>
#include<cmath>
using namespace std;
int k,n,i;
long long ans;

int main(){
    cin>>k>>n;
    i=0;
    ans =0;
    while(n){
        ans +=(n&1) * pow(k,i);
        i++;
        n>>=1;
    }
    cout<<ans;
    return 0;
}
