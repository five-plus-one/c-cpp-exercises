#include<iostream>
using namespace std;
int n,t[1000010],p[1000010],flag;
char b[1000010];
double r=0;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    flag = 1;
    r=0;
    for(int i=1;i<=n;i++){
        if(double(t[i])/double(p[i])>r) {flag=i;r=double(t[i])/double(p[i]);}
    }
    if(b[flag]=='K'){
        cout<<"Crazy Thursday";
    }else{
        cout<<"Maimai yyds";
    }
    return 0;
}