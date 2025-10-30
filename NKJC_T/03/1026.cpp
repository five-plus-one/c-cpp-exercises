#include<iostream>
using namespace std;

int a[1010],maxnum,n,T;
bool judge(int maxnumber,int nm){
    int count =0;
    for(int i2=1;i2<=nm;i2++){
        if(a[i2]>=maxnumber){
            count++;
        }
    }
    return count>=maxnumber+0;
}
int main(){
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        maxnum = 0;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            if(a[j]>maxnum){
                maxnum = a[j];
            }
        }
        // cout<<maxnum;
        // cout<<endl<<judge(2,5);
        // cin>>T;
        // cout<<judge(maxnum,n);
        while(!judge(maxnum,n)){
            maxnum--;
        }
        cout<<maxnum<<endl;

    }
    return 0;
}
