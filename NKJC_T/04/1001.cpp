#include<iostream>
#include<cstdio>
using namespace std;
int T,n,an,maxnum,minnum,jc;
long long sumnum;
const long long N = 1e5+10;
double averagenum,fc,fcz;
int num[N];
int main(){
    cin>>T;
    for(int j=1;j<=T;j++){
        cin>>n;
        sumnum=0;
        for(int i=1;i<=n;i++){
            cin>>an;
            num[i]=an;
            sumnum+=an;
            if(i==1){
                maxnum=minnum=an;
            }else {
                if(an > maxnum){maxnum=an;}
                if(an < minnum){minnum=an;}
            }
        }
        jc=maxnum-minnum;
        averagenum = sumnum *1.0 / n;
        fcz=0;
        for(int i=1;i<=n;i++){
            fcz+=(num[i]-averagenum)*(num[i]-averagenum);
        }
        fc=fcz/n;
        printf("%d %.3f",jc,fc);cout<<endl;
    }
}