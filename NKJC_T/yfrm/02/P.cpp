#include<iostream>
#include<cstdio>
using namespace std;
int yyyy,mm,dd;
bool judge(int m,int d){
    if(m<10){
        return true;
    }else if(m==10 && d<29){
        return true;
    }else {
        return false;
    }
}
int main(){
    scanf("%d/%d/%d",&yyyy,&mm,&dd);
    if(judge(mm,dd)){
        cout<<"No. It's not too late.";
    }else {
        cout<<"QAQ";
    }
    return 0;
}