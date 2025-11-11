#include<iostream>
using namespace std;
int main(){
    int x,n,d;
    cin>>x>>n;
    d=(x+n)%7;
    if(d==0) {
        d=7;
    }
    cout<<d;
}