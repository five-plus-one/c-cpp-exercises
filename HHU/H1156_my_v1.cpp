#include<iostream>
using namespace std;
int A,x,B,C,D,i;
bool flag = false;
double r,money;
int main(){
    cin>>r>>B>>C>>D;
    r=r/100;
    A = 0;
    while(flag == false) {
        A++;
        money = A;
        for(i=1;i<=D;i++){
            money = money*(1+r) - (B * i + C);
        }
        if(money>=0){
            flag = true;
        }
    }
    cout<<A;
}