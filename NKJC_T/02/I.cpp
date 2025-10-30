#include<iostream>
using namespace std;
long long n;
int main(){
    cin>>n;
    if(n>50 && n % 2 ==0){
        cout<<"yes";
    }else {
        cout<<"no";
    }
    return 0;
}