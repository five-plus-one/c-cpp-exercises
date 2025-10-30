#include<iostream>
#include<cmath>
using namespace std;
long long n,i,m;
int main(){
    cin>>n;
    m=0;
    for(i=1;i<sqrt(n);i++){
        if(n % i==0){
            m+=i;
            m+=n/i;
        }
    }
    if(i==sqrt(n)){m+=sqrt(n);}
    cout<<m;
    return 0;

}