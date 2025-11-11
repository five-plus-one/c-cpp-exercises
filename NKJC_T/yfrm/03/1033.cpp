#include<iostream>
using namespace std;
long long n,maxnum,minnum,sumnum,n2;
double averagenum;
int main(){
    cin>>n2;
    sumnum=0;
    for (int i=1;i<=n2;i++){
        cin>>n;
        sumnum+=n;
        if(i==1){
            maxnum=minnum=n;
        }else {
            if(n>maxnum){
                maxnum=n;
            }else if(n<minnum){
                minnum=n;
            }
        }
    }
    averagenum = double(sumnum)/n2;
    printf("%.2f %d %d",averagenum,maxnum,minnum);
    return 0;
}