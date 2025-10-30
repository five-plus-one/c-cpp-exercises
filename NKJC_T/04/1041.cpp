#include<iostream>
using namespace std;
int count[200]={};
bool iszs(int n){
    int i=2;
    if(n==1 || n==0){return false;}
    while(i*i<=n && i<n){
        if(n%i ==0){
            return false;
        }
        i++;
    }
    return true;
}
int main(){
    string str;
    cin>>str;
    int total = str.length();
    for(int i=0;i<total;i++){
        int tmp = str[i];
        if(tmp<='Z'){tmp+=32;}
        count[str[i]]++;
    }
    int maxn = 1;int minn = 9999;
    for(int i='a';i<='z';i++){
        int tmp = count[i];
        if(tmp>0){
            if(tmp>maxn){maxn=tmp;}
            if(tmp<minn){minn=tmp;}
        }
    }
    int ans = maxn-minn;
    if(iszs(ans)){
        printf("Lucky Word\n%d",ans);
    }else {
        printf("No Answer\n0");
    }
    return 0;
}