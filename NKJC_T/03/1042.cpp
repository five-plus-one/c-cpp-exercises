#include<iostream>
using namespace std;
int h[20],l1,count=0;
int main(){
    for(int i=1;i<=10;i++){
        cin>>h[i];
    }
    cin>>l1;
    for(int i=1;i<=10;i++){
        if(l1+30>=h[i]){
            count++;
        }
    }
    cout<<count;
    return 0;
}