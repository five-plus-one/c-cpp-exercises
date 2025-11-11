#include<iostream>
using namespace std;
void blank(int n){
    for (int i=1;i<=n;i++) cout<<" ";
}
void xx(int n) {
    for (int i=1;i<=n;i++) cout<<"*";
}
void draw(int n){
    int i;
    for(i=1;i<=n;i++){
        blank((n-i+1)*2);xx(i);cout<<endl;
    }
    xx(i);cout<<endl;
    for(i = n;i>0;i--){
        blank((n-i+1)*2);xx(i);cout<<endl;
    }
}
int main(){
    int n;
    while(cin>>n){
    draw(n);}
    return 0;
}