#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N= 2*1e5+10;
struct st{
    int dis;
    int num;
}p[N];
int n,minpos,currentpos;
ll currentdistance,mindistance;
bool comp(st a,st b){
    return a.dis<b.dis;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i].dis);
    }
    currentpos = 1;
    minpos = 1;
    currentdistance = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i].num);
    }
    // sort(p+1,p+1+n,comp);
    int startdis = p[1].dis;
    for(int i=2;i<=n;i++){
        currentdistance+=(p[i].dis-startdis)*p[i].num;
    }
    mindistance = currentdistance;
    for(int i=2;i<=n;i++){
        currentdistance+=(p[i-1].num-p[i].num)*(p[i].dis-p[i-1].dis);
        if(currentdistance < mindistance){
            mindistance = currentdistance;
            minpos = i;
        }
    }
    printf("%d\n",minpos);
    return 0;
}