#include<iostream>
using namespace std;
long long a,b,n;
int main(){
    cin>>a>>b>>n;
    if((n - (abs(a)+abs(b)))%2 ==0 && n>=(abs(a)+abs(b))){
        cout<<"YES";
    }else {
        cout<<"NO";
    }
    return 0;
}