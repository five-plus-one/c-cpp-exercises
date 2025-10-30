#include<iostream>
using namespace std;
int T,a[5],maxflag,minflag;
void getyg(){
    int maxnum=a[1],minnum=a[1],maxcount=0,mincount=0;
    for(int i=2;i<=4;i++){
        if(a[i]>maxnum){maxnum=a[i];}
        if(a[i]<minnum){minnum=a[i];}
    }
    for(int i=1;i<=4;i++){
        if(a[i]==maxnum){maxflag = i;maxcount++;}
        if(a[i]==minnum){minflag = i;mincount++;}
    }
    if(maxcount>1){maxflag = -1;}
    if(mincount>1){minflag = -1;}

}
void printans(int m){
    printf("%c\n",'A'+m-1);
}
int main(){
    string str;
    cin>>T;
    for(int j=1;j<=T;j++){
        for(int i=1;i<=4;i++){
            cin>>str;
            a[i]=str.length();
        }
        getyg();
        if(maxflag>0 && minflag == -1){
            printans(maxflag);
        }else if(minflag>0 && maxflag ==-1){
            printans(minflag);
        }else{
            printans(3);
        }
    }
    return 0;
}
