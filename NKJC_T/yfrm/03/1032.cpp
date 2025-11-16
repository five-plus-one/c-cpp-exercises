#include<iostream>
using namespace std;
long long n,maxnum,minnum,an,i;

int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>an;
        if(i == 1){
            maxnum = an;minnum=an;
        }else {
            if( an > maxnum){
                maxnum = an;
            }else if(an < minnum){
                minnum = an;
            }
        }
    }
    cout<<maxnum-minnum;
    return 0;
}
