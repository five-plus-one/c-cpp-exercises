#include<iostream>
using namespace std;
long long n,ai,bi,i,count;
int status1,status2;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        bi=ai;
        cin>>ai;
        if(i>=2){
            if(ai>bi){
                status2=status1;
                status1=3;
            }else if(ai<bi){
                status2=status1;
                status1=2;
            }
            if(status1==2&&status2==3){
                count++;
            }
        }
    }
    cout<<count;
}