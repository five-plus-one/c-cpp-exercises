#include<iostream>
using namespace std;
double cal(double n){
    if(int(n) % 2 ==0){
        return -1/n;
    }else {
        return 1/n;
    }
}
int main(){
    double n,ans=0;
    cin>>n;
    for(double i=1;i<=n;i++){
        ans += cal(i);
    }
    printf("%.3f",ans);
    return 0;
}