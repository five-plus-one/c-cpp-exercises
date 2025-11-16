#include<iostream>
using namespace std;
char ch;
int count=0;

int main(){
    while(ch!='.'){
        scanf("%1c",&ch);
        if(ch == 'a'){
            count++;
        }
    }
    cout<<count;
    return 0;
}