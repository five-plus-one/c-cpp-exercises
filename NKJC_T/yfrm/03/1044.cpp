#include<iostream>
using namespace std;
double sn=0;
int n,k;
int main(){
    cin>>k;
    n=0;
    while(sn<=k){
        n++;
        sn+=1.0/n;
    }
    cout<<n;
}