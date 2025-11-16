
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double n,a1,b1,c1,a2,b2,c2;
int main(){
    cin>>n;
    a1=floor(n*0.1);
    b1=floor(n*0.2);
    c1=floor(n*0.3);
    a2=ceil(n*0.1);
    b2=ceil(n*0.2);
    c2=ceil(n*0.3);
    cout<<a2-a1<<" "<<a2+b2-(a1+b1)<<" "<<a2+b2+c2-(a1+b1+c1);
    return 0;
}