#include<iostream>
using namespace std;
int n;
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    int x = 1;
    while( (x*n) % 10 != 0) x++;
    cout<<x;
}