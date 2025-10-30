#include<iostream>
using namespace std;
int a[15],i,total,bf;
int main(){
    for(i=1;i<=10;i++){
        cin>>a[i];
    }
    total=0;bf=0;
    for(i=1;i<=10;i++){
        total+=a[i];
        if(abs(total-100)<=abs(bf-100)){
            bf=total;
        }
    }
    cout<<bf;
}