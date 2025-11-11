#include<iostream>
using namespace std;
int main(){
    double A,B,C,Avg;
    cin>>A>>B>>C;
    Avg=(A+B+C)/3;
    if(Avg < 60){
        cout<<"YES";
    }else {
        cout<<"NO";
    }
    return 0;
}