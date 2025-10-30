#include<iostream>
using namespace std;
long long n,m,x,y;
int main(){
    cin>>n>>m;
    x=2*n-(m/2);
    y=m/2 -n;
    printf("%lld %lld",x,y);
}