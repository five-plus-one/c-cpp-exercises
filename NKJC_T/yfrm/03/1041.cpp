#include<iostream>
using namespace std;
int n,count=0;
int main(){
    cin>>n;
    while(n!=1){
        if(n%2==0){
            n/=2;
        }else {
            n=3*n+1;
        }
        count++;
    }
    cout<<count;
    return 0;
}