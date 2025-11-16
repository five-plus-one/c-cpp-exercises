#include<iostream>
using namespace std;
long long weight;
int main(){
    cin>>weight;
    if(weight%2 == 0 && weight>=4){
        cout<<"YES, you can divide the watermelon into two even parts.";
    }else {
        cout<<"NO, you can't divide the watermelon into two even parts.";
    }
    return 0;
}