#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,a1,a2,b1,b2,c1,c2,minmoney;

int calculatemoney(int n,int a,int b){
    return(ceil(float(n)/float(a)) * b);
}
int main(){
    cin>>n>>a1>>a2>>b1>>b2>>c1>>c2;
    minmoney = min(min(calculatemoney(n,a1,a2),calculatemoney(n,b1,b2)),calculatemoney(n,c1,c2));
    cout<<minmoney;
    return 0;
}
