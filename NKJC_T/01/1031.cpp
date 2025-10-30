#include<iostream>
using namespace std;
int seconds,h,m,s;
int main(){
    cin>>seconds;
    h=seconds/3600;
    m=(seconds-3600*h)/60;
    s=(seconds-h*3600-m*60);
    cout<<h<<" "<<m<<" "<<s;
    return 0;
}