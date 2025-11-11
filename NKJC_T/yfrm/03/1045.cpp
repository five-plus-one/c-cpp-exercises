#include<iostream>
using namespace std;
int a,b,T;
int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>a>>b;
        if(b==15){
            cout<<14;
        }else if(b==0){
            cout<<1;
        }else{
            cout<<2*b-a;
        }
        if(i<T){
        cout<<endl;}
    }
    return 0;
}