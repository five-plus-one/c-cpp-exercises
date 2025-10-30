#include<iostream>
using namespace std;
int cal(int n){
    if(n ==1 || n==2){
        return 1;
    }else {
        return( cal(n-1)+cal(n-2));
    }
}
int main(){
    int n;
    cin>>n;
    cout<<cal(n);
    return 0;
}