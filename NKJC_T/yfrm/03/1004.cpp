#include<iostream>
using namespace std;
void blank(int n){
    for (int i=1;i<=n;i++) cout<<" ";
}
void xx(int n) {
    for (int i=1;i<=n;i++) cout<<"*";
}
void draw(int n){
    n = (n+1)/2;
    for(int i=1;i<=n;i++){
        blank(n-i);xx(2*i-1);cout<<endl;
    }
    for(int i=n-1;i>0;i--){
        blank(n-i);xx(2*i-1);cout<<endl;
    }
}
int main(){
    int T,n;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;draw(n);
    }
    return 0;
}