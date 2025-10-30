#include<iostream>
using namespace std;
long long n;
int main(){
    cin>>n;
    if(n % 400 ==0 || (n%4 ==0 && n%100 !=0)){
        cout<<"yes";
    }else {
        cout<<"no";
    }
    return 0;
}