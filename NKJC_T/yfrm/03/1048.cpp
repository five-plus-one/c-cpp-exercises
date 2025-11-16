#include<iostream>
using namespace std;

bool ishaoshu(int n){
    return (n/100)*(n/10%10)%10 == n %10;
}
int t,l,r,count;
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>l>>r;
        count =0;
        for(int j=l;j<=r;j++){
            count+=ishaoshu(j);
        }
        cout<<count<<endl;
    }
}