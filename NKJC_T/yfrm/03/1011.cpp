#include<iostream>
using namespace std;
int cal(int n){
    if(n ==1){
        return 0;
    }else if(n ==2 || n==3){
        return 1;
    }else {
        return(cal(n-3)+2*cal(n-2)+cal(n-1));
    }
}
int main(){
    int n;
    cin>>n;
    cout<<cal(n);
    return 0;
}