#include<iostream>
using namespace std;
long long a,b;
int main(){
    cin>>a>>b;
    if(b%a == 0){
        cout<<a+b;
    }else {
        cout<<b-a;
    }
    return 0;
}