#include<iostream>
using namespace std;
bool containalan(string str){
    int n = str.length();
    for(int i=0;i<=n-4;i++){
        string s2 = str.substr(i,4);
        if((s2[0]=='A'||s2[0]=='a')&&(s2[1]=='L'||s2[1]=='l')&&(s2[2]=='A'||s2[2]=='a')&&(s2[3]=='N'||s2[3]=='n')){
            return true;
        }
    }
    return false;
}
int main(){
    int n,cnt = 0;
    string str;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>str;
        cnt+=containalan(str);
    }
    cout<<cnt;
}