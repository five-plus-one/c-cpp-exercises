#include<iostream>
#include<cstdio>
using namespace std;
char ch;int count;
int main(){
    count = 0;
    while(scanf("%1c",&ch)!=EOF){
        if(ch !=' '){
        count++;}
    }
    count --;
    cout<<count;
    return 0;
}