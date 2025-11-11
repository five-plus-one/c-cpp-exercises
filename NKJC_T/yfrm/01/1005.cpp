#include<iostream>
using namespace std;
int main (){
    int i=0,j=0;
    for(i=1;i<=9;i++){
        for(j=1;j<=i;j++){
            cout<<j<<"*"<<i<<"=";
            if(i*j<10){
                cout<<" ";
            }
            cout<<i*j;
            if(i!=j){
                cout<<" ";
            }

        }
        if(i<9){
            cout<<endl;
        }
    }
}