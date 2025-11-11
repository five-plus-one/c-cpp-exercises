#include<iostream>
using namespace std;
int n;
void blank(int n){
    for (int i=1;i<=n;i++) cout<<" ";
}
void xx(int n) {
    for (int i=1;i<=n;i++) cout<<"*";
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        blank(n-i);xx(2*i-1);cout<<endl;
    }
    for(int i=n-1;i>0;i--){
        blank(n-i);xx(2*i-1);cout<<endl;
    }
    return 0;
}