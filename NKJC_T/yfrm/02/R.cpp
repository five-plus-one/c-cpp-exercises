#include<iostream>
#include<cstdio>
using namespace std;
double N,ans;

int main(){
    cin>>N;
    ans = N * 12*25.4;
    if(ans - int(ans) ==0){
        cout<<ans;
    }else {
        printf("%.1f",ans);
    }
    return 0;
}