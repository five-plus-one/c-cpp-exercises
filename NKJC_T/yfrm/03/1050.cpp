#include<iostream>
using namespace std;

bool ishuiwen(long long n){
    bool flag = true;
    int s[15],i=0,count;
    while(n>=1){
        i++;
        s[i]=n%10;
        n/=10;
    }
    count =i;
    for(i=1;i<=count/2+1;i++){
        if(s[i]!=s[count+1-i]){
            flag = false;
        }
    }
    return flag;
}

int main(){
    long long n,i;
    cin>>n;
    for(i=1;i<=n;i++){
        if(ishuiwen(i)){
            cout<<i<<endl;
        }
    }
    return 0;
}