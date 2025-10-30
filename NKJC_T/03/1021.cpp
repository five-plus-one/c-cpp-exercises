#include<iostream>
using namespace std;
long long k,days,i,money;
int main(){
    cin>>k;
    money = 0;
    i = 1;
    days = 0;
    while(days+i < k){
        days +=i;
        money += i*i;
        i++;
    }money +=(k-days)*i;
    cout<<money;
}