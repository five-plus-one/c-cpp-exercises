#include<iostream>
using namespace std;

int calculatenum(int n,int x){
    int count=0;
    while(n){
        if(n%10==x){
            count++;
        }
        n/=10;
    }
    return count;
}
int main(){
    int n,x,c=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        c+=calculatenum(i,x);
    }
    cout<<c;
    return 0;
}