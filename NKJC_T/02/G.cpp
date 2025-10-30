#include<iostream>
using namespace std;
long long n;
int main(){
    cin>>n;
    if((n-1)%2 == 0){
        cout<<n;
    }else {
        cout<<-1;
    }
    return 0;
}