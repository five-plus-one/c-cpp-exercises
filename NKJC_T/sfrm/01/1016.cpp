#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n,totallen,dis[N],qzh[N];
int caldis(int a,int b){
    if(a > b) return caldis(b,a);
    int dis1 = qzh[b-1]-qzh[a-1];
    int dis2 = totallen - dis1;
    return min(dis1,dis2);
}
int main(){
    scanf("%d",&n);
    totallen = 0; qzh[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&dis[i]);
        qzh[i] = qzh[i-1] + dis[i];
        totallen += dis[i];
    }
    int maxlen = 0;
    for(int left = 1,right = 1; left <=n ; left++){
        bool flag;
        int len;
        while(right<=n && (flag =(len = caldis(left,right)) < caldis(left,right+1))){
            right++;
        }
        if(flag == false){
            if(len > maxlen){
                maxlen = len;
            }
        }
    }
    printf("%d\n",maxlen);
}