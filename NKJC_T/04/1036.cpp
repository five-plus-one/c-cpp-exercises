#include<iostream>
using namespace std;
int main(){
    string str;
    cin>>str;
    int n = str.length();
    int cnt =-1;
    for(int i=2;i<=n;i++){
        if((str[i-2]=='b'||str[i-2]=='B')&&(str[i-1]=='o'||str[i-1]=='O')&&(str[i-0]=='b'||str[i-0]=='B')){
            cnt =i-2;break;
        }
    }
    cout<<cnt;
}