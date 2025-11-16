#include<iostream>
using namespace std;
int T,N,M,count,money;
int main(){
    cin>> T;
    for(int i=1;i<=T;i++){
        cin>>N>>M;
        count = 0;
        for(int j=1;j<=M;j++){
            cin>>money;
            if(N>=money){
                N-=money;
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}