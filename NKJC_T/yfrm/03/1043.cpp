#include<iostream>
using namespace std;
int money=0,budget,deposit=0,depositadd;
int main(){
    for(int i=1;i<=12;i++){
        cin>>budget;
        money+=300;
        if(money<budget){
            // cout<<"第"<<i<<"月，钱"<<money<<"预算"<<budget<<"破产"<<endl;
            cout<<"-"<<i;
            return 0;
        }else {
            depositadd=((money-budget)/100)*100;
            deposit+=depositadd;
            money=money-budget-depositadd;
            // cout<<"第"<<i<<"月，预算"<<budget<<"剩余钱"<<money<<"存款"<<deposit<<""<<endl;
        }
    }
    cout<<money+deposit*1.2;
    return 0;
}