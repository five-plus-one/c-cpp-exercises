#include<iostream>
using namespace std;
long long n,l,ln,i,maxtime;
int main(){
    cin>>l>>n;
    for(i=1;i<=n;i++){
        cin>>ln;
        if(i==1){
            maxtime = min(ln,l-ln);
        }else {
            if(min(ln,l-ln)>maxtime){
                maxtime = min(ln,l-ln);
            }
        }
    }
    cout<<maxtime;
}