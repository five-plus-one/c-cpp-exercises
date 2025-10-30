//50TE
#include<iostream>
using namespace std;
const int N = 2*1e5+10;
int a[N];

int main(){
    int T,x,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int ans = 0;
        for(int l=1;l<=n;l++){
            int cnt = 0;
            for(int r=l;r<=n;r++){
                cnt+=a[r];
                if(cnt % x==0){ans++;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}