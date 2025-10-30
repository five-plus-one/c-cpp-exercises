#include<iostream>
using namespace std;
long long n,a,b;
int main(){
    cin>>a>>b;
    for(n=a;n<=b;n++){
    if(n % 400 ==0 || (n%4 ==0 && n%100 !=0)){
        cout<<n<<endl;
    }
}
    return 0;
}