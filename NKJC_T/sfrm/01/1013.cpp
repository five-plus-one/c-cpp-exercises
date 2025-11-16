#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N= 2*1e5+10;
struct st{
    int dis;
    int num;
    ll qzh;
}p[N];
int n,minpos,currentpos;
ll currentdistance,mindistance;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i].dis);
    }
    minpos = 1;
    currentdistance = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i].num);
    }
    // sort(p+1,p+1+n,comp);
    int startdis = p[1].dis;
    p[0].qzh = 0; p[1].qzh =p[1].num;
    for(int i=2;i<=n;i++){
        currentdistance+=(p[i].dis-startdis)*p[i].num;
        p[i].qzh = p[i-1].qzh + p[i].num;
    }
    mindistance = currentdistance;
    for(int i=2;i<=n;i++){
        currentdistance+=(p[i-1].qzh - (p[n].qzh - p[i-1].qzh))*(p[i].dis-p[i-1].dis);
        if(currentdistance < mindistance){
            mindistance = currentdistance;
            minpos = i;
        }
    }
    printf("%d\n",minpos);
    return 0;
}