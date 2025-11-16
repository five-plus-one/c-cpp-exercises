#include<iostream>
using namespace  std;
long long count1,count5,count10,mn;
int k;
void calculate(int n){
    if(n == 1){
        count1++;
    }else if(n == 5){
        count5++;
    }else if(n == 10){
        count10++;
    }
}
int main(){
    count1=0;count5=0;count10=0;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>mn;
        calculate(mn);
    }
    cout<<count1<<" "<<count5<<" "<<count10;
}