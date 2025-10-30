//64TLE
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e5+10;
int a[N][20];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int maxminbk = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int minbk = max(a[i][1],a[j][1]);
            for(int k=2;k<=m;k++){
                if(max(a[i][k],a[j][k])<minbk){
                    minbk = max(a[i][k],a[j][k]);
                }
            }
            if(minbk >maxminbk){
                maxminbk = minbk;
            }
        }
    }
    printf("%d",maxminbk);
}