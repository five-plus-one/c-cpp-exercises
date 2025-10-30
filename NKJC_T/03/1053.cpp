#include<iostream>
using namespace std;
int h[]={2,0,3,3,1,3,3,1,3,3},
    s[]={4,2,2,2,3,2,3,2,4,3},
    T,a;

int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>a;
        cout<<h[a]<<" "<<s[a]<<endl;
    }
}