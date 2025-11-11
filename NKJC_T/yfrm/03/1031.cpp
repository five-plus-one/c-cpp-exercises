#include<iostream>
#include<cmath>

using namespace std;

long long N,n,total1,else1;
double n2;

int main(){
    cin>>N;
    n2 = (-1+sqrt(1+8*double(N)))/2;
    n = floor(n2);
    if(n2 == n){
        n--;
    }
    // cout<<n<<endl;
    total1 = (1+n)*n/2;
    else1 = N-total1;
    if(n%2 == 0){
        cout<<(n+1)-(else1-1)<<"/"<<else1;
    }else{
        cout<<else1<<"/"<<(n+1)-(else1-1);
    }
    return 0;
}