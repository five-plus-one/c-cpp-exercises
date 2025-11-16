#include<iostream>
using namespace std;

int swzh(long long n){
    if(n<0){
        return swzh(-n);
    }else{
        int count=0;
        while(n){
            count+=n%10;n/=10;
        }
        return count;
    }

}
int main(){
    long long n;
    cin>>n;
    cout<<swzh(n);
}