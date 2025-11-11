#include<iostream>
using namespace std;
int a,b,c,d,maxnum,minnum;
int main(){
    cin>>a>>b>>c>>d;
    maxnum=max(max(max(a,b),c),d);
    minnum=min(min(min(a,b),c),d);
    cout<<abs(a+b+c+d-2*(maxnum+minnum));
}