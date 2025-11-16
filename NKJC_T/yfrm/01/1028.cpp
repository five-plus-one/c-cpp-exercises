#include<iostream>
using namespace std;
int a,b,c;
int main(){
    cin>>a>>b>>c;
    cout<<2*(a*b+b*c+c*a)<<endl
        <<a*b*c;
    return 0;
}