#include<iostream>
using namespace std;
long long n,ai,i,minji,jicount,sumnum;

int main(){
    sumnum = 0;
    cin>>n;
    jicount = 0;
    for(int i =1;i<=n;i++){
        cin>>ai;
        sumnum+=ai;
        if(ai % 2 ==1){
            jicount ++;
            if(jicount == 1){
                minji=ai;
            }else{
                if(ai < minji){
                    minji = ai;
                }
            }
        }
    }
    if(jicount % 2 ==1){
        sumnum -=minji;
    }
    cout<<sumnum;
    return 0;
}