#include<iostream>
#include<cmath>
using namespace std;
double a;
int main(){
    cin>>a;
    cout<<int(floor(fabs(a)/10)) % 10;
}