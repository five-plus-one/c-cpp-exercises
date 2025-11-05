//5plus1
#include<iostream>
#include<cstdio>
using namespace std;
using ll = long long;
const int N = 1e5+10;
int a[N],n,opt,q,x;
ll ai,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&ai);
        a[i]=ai%2;
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d%lld",&opt,&x,&y);
        if(opt ==1){
            a[x]+=y%2;
            a[x]%=2;
        }else{
            ll cnt = 0;
            for(int j=x;j<=y;j++){
                cnt+=a[j];
            }
            if(cnt%2==0){
                printf("1145141919810\n");
            }else{
                printf("0\n");
            }
        }
    }
}