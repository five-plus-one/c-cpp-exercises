// 45 Time Exceeded
#include<iostream>
using namespace std;
int T,N,i,count,e,etotal,No;
bool status;
int main(){
    cin>>T;
    for(i=1;i<=T;i++) {
        cin>>N;
        No=N;
        count = 0;
        status = false;
        while(status == false){
            etotal = 0;
            e=0;
            count++;
            while(etotal<=N-(e+1)){
                e++;
                etotal+=e;
            }
            if(etotal ==N ){
                status = true;
            }
            else{N = N-etotal + No;}
        }
        cout<<count<<endl;
    }
}