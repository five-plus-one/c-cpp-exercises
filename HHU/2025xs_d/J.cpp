#include<iostream>
using namespace std;
const int N = 1e6*5+10;
int T,n,a[N];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int maxnum = 0,maxpos = -1,k=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]+i > maxnum){
                maxnum = a[i] + i;
                maxpos = i; 
            }
        }
        int minmaxnum = maxnum,minmaxk = 0;
        for(k = 1;k<n;k++){
            if(maxpos == k-1){
                maxnum = a[k-1]+(n-1);
            }else{
                maxnum --;
                if(a[k-1]+(n-1) > maxnum){
                    maxnum = a[k-1]+(n-1);
                    maxpos = k-1;
                }
            }
            if(maxnum < minmaxnum){
                minmaxnum = maxnum;
                minmaxk = k;
            }
        }
        printf("%d\n",minmaxnum);
    }
}