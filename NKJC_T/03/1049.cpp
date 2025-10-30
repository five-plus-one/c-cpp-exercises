#include<iostream>
using namespace std;
long long n,i;

bool ishaoshu(long long n){
    return ((n%3==2)&&(n%5==3)&&(n%7)==2);
}

int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        if(ishaoshu(i)){
            cout<<i<<endl;
        }
    }
    return 0;
}