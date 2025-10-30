#include<iostream>
using namespace std;
char s[20];
char o[20];
int i;
int main(){
    for(i=1;i<=6;i++){
        cin>>s;
        o[i] = s[0];
    }
    for(i=1;i<=6;i++){
        cout<<o[i];
    }
}