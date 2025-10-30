//P1018 
#include<iostream>
using namespace std;
long long n,count;
int main(){
    while(cin>>n){
        count = 0;
        for(int i=1;i<=64;i++){
            if((n&1) == 1){
                count++;
            }
            n >>=1;
        }
        cout<<count<<endl;
    }
}
