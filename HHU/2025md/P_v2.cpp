//5plus1
#include<iostream>
#include<cstdio>
using namespace std;
using ll = long long;
const int N = 1e5+10;
int a[N],n,opt,q,x,qzh[N];
ll ai,y;
bool updateqzhstatus = false;
void updateqzh(int x){
    qzh[0] = 0;
    for(int i=x;i<=n;i++){
        qzh[i] = qzh[i-1] + a[i];
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&ai);
        a[i]=ai%2;
    }
    updateqzh(1);
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d%lld",&opt,&x,&y);
        if(opt ==1){
            a[x]+=y%2;
            a[x]%=2;
            updateqzh(x);
        }else{
            ll cnt = qzh[y]-qzh[x-1];
            if(cnt%2==0){
                printf("1145141919810\n");
            }else{
                printf("0\n");
            }
        }
    }
}