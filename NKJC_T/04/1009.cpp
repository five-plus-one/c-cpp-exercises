#include<iostream>
using namespace std;
int N,M,A,Mi,count[1010];
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>A;
        for(int j=1;j<=A;j++){
            cin>>Mi;
            count[Mi]++;
        }
    }
    int total = 0;
    for(int i=1;i<=M;i++){
        total+=(count[i] == N);
    }
    cout<<total;
}