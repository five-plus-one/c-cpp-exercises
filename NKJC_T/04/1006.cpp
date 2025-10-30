#include<iostream>
using namespace std;
int n,maxid,minid,maxnum,minnum,ni;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ni;
        if(i==1){maxnum=minnum=ni;maxid=minid=1;}
        if(ni > maxnum){
            maxnum = ni;maxid=i;
        }else if(ni < minnum){
            minnum = ni;minid=i;
        }
    }
    int mindis =  min(min(maxid-1,n-maxid),min(minid-1,n-minid));
    int ans = n-(mindis+1);
    cout<<ans;
}