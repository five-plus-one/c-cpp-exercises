#include<iostream>
using namespace std;
int main(){
    string N;
    cin>>N;
    int n = N.length();
    int count = (n+2)/3; 
    int gcount = n-(count-1)*3;
    cout<<N.substr(0,gcount);
    for(int i=2;i<=count;i++){
        cout<<","<<N.substr(gcount+(i-2)*3,3);
    }
    
}