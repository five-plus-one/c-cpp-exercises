#include<iostream>
using namespace std;
int n,ai;
int main(){
    cin>>n;
    for(int i=n;i>=0;i--){
        cin>>ai;
        if(i<n&&ai!=0){
            if(ai>0){cout<<"+";}
            else if(ai<0){cout<<"-";}
        }
        if(i==n&&ai!=0){
            if(ai<0){cout<<"-";}
        }
        if(ai!=0){
            if(abs(ai)!=1||i==0){
            cout<<abs(ai);}
            if(i>0){
                if(i==1){cout<<"x";}else{
                cout<<"x^"<<i;}
            }
        }
    }
}