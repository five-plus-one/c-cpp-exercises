#include<iostream>
using namespace std;
long long n,p,m;
int main(){
    p=0;n=0;
    for(int i=1;i<=10;i++){
        cin>>m;
        if(m>0){
            p++;
        } else if(m<0){
            n++;
        }
    }
    cout<<"positive:"<<p<<endl
        <<"negative:"<<n;
    return 0;
}