#include<iostream>
using namespace std;
char convert(char a){
    if(a<='Z'){return a;}
    else return(a-32);
}
int main(){
    string s1,s2="";
    while(cin>>s1){
        s2+=convert(s1[0]);
    }
    cout<<s2;
}