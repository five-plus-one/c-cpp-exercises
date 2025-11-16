#include<iostream>
using namespace std;
const int N =1e5+10;
int n,a[N],b[N],g[N],k[N],x,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
    }
    scanf("%d%d",&x,&y);
    int ans = -1;
    for(int i=n;i>0;i--){
        if(x>=a[i]&&x<=a[i]+g[i]&&y>=b[i]&&y<=b[i]+k[i]){
            ans = i;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}