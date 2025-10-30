#include<iostream>
using namespace std;
int num[]={2,3,5,7};
bool judge(int x){
    int count=0;
    for(int i=0;i<4;i++){
        if(x % num[i] ==0){count++;}
    }
    if(count==2){
        return true;
    }else{
        return false;
    }
}



int main(){
    int l,r,i,ans=0;
    cin>>l>>r;
    for (i=l;i<=r;i++){
        if(judge(i)){ans++;}
    }
    cout<<ans;
    return 0;
}