#include<iostream>
#include<cmath>
using namespace std;
long long zs=2 ,count=0,n;

bool iszs(long long x){
    if(x == 1){
        return false;
    }else{
    long long i=1;
    bool iszs = true;
    while(iszs && i<=sqrt(x)){
        i++;
        if(x % i == 0){
            iszs = false;
        }
    }
    return iszs;}
}
void nextzs(){
    zs++;
    while(!iszs(zs)){
        zs++;
    }
}
int main(){
    cin>>n;
    count =0;
    while(n!=1){
        if(n%zs == 0){
            count++;
            n/=zs;
        }else {
            nextzs();
        }
    }
    if(count % 2==0){
        cout<<"Johnson";
    }else {
        cout<<"Nancy";
    }
}