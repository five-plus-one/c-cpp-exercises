//前缀和
#include<iostream>
using namespace std;
using ll = long long;
int n,q,ai,l,r;
const int N =1e6+20;
ll qzh[N];
int main(){
    scanf("%d%d",&n,&q);
    qzh[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&ai);
        qzh[i] = qzh[i-1] +ai;
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&l,&r);
        printf("%lld\n",qzh[r]-qzh[l-1]);
    }
}