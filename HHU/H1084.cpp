#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main(){
    int T;
    string str,s;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>str;
        if(str.size()==11){
           s=str[0]+str[1]+str[2];
           cout<<s;
        }
        else {
            printf("NoNoNo");
        }
    }
}