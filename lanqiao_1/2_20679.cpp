#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    char s;
    while (1) {
        s = getchar();
        if(s == EOF) break;
        if('a'<= s && s<='z'){
            putchar('L');
        }else if( '0'<= s && s<='9'){
            putchar('Q');
        }
        
    }
    return 0;
}