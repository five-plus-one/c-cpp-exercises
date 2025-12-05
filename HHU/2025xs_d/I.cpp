#include<iostream>
#include<cstring>
using namespace std;
const int N = 2*1e5+10;
int issw[N],n,m,s,a,b;
void fh(){
    memset(issw,0,sizeof(issw));
}
bool solve(int a,int b){
    if(issw[a]==1 || issw[b] == 1 || a==b){
        return 0;
    }else{
    	issw[b] = 1; 
        if(b == s){
            fh();
        }
        return 1;
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&s);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        int ans = solve(a,b);
        printf("%d ",ans);
    }
}