#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double a,b,c;
int main(){
    cin>>a>>b>>c;
    cout<<4*(sqrt(b*c/a)+sqrt(a*b/c)+sqrt(a*c/b));
    return 0;
}