//v2 5plus1
#include<iostream>
using namespace std;
void solve(int n,char s,char t,char r,int &count,int &tc,int m,bool &end){
    if(n==0 || end == true){
        return;
    }else{
        solve(n-1,s,r,t,count,tc,m,end);
        count++;
        // cout<<"第"<<count<<"次，将"<<n<<"从"<<s<<"到"<<t<<endl;
        if(m==count){tc = n;end=true;}
        solve(n-1,r,t,s,count,tc,m,end);
    }
}
int main(){
    int T,n,m,num;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d%d",&n,&m);
        int count = 0;
        bool end = false;
        solve(n,'A','C','B',count,num,m,end);
        printf("%d\n",num);
    }
    return 0;
}