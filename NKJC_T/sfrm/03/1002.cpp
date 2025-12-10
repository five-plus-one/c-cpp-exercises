#include<iostream>
using namespace std;
const int N = 5 * 1e4 + 10;
int n,q,time2[N],bi,ti;
int solve(int t){
    int l = 1 ,r = n;
    while(1) {
        int mid = (l + r) / 2;
        if(time2[mid]>t && time2[mid-1]<=t){
            return mid;
        }else if(time2[mid]<=t){
            l = mid+1;
        }else{
            r = mid -1;
        }
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&bi);
        time2[i] = time2[i-1] + bi;
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d\n",time2[i]);
    // }
    // printf("\n\n");
    for(int i=1;i<=q;i++){
        scanf("%d",&ti);
        printf("%d\n",solve(ti));
    }
    return 0;
}