#include<iostream>
using namespace std;
int n,x,maxnum,maxnum2,minnum,minnum2;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i == 1){
            maxnum=maxnum2=minnum=minnum2=x;
        }else {
            if(x > maxnum){
                maxnum2=maxnum;
                maxnum=x;
            }else if(x<minnum){
                minnum2=minnum;
                minnum=x;
            }else if(maxnum>x && x>maxnum2){
                maxnum2 =x;
            }else if(minnum<x && x<minnum2){
                minnum2 = x;
            }else if(maxnum==maxnum2 && x<maxnum2){
                maxnum2 = x;
            }else if(minnum==minnum2 && x>minnum2){
                minnum2 = x;
            }
        }
    }
    // cout<<maxnum<<maxnum2<<minnum<<minnum2<<endl<<endl;
    cout<<maxnum-maxnum2<<" "<<maxnum-minnum2<<" "<<maxnum2-minnum2<<" "<<maxnum2-minnum;
    return 0;
}