#include<iostream>
using namespace std;
char ch;

int main(){
    while((ch=getchar())!=EOF){
        if(ch == '5'){
            cout<<"*";
        }else {
            cout<<ch;
        }
    }
    return 0;
}