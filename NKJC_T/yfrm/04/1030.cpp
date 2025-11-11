#include<iostream>
using namespace std;
using ll = long long;
struct point{
    ll x;
    ll y;
    ll dis2;
};
int n;
point p[15];
int main(){{}
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&p[i].x,&p[i].y);
        p[i].dis2 = p[i].x*p[i].x+p[i].y*p[i].y;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            if(p[j].dis2>p[j+1].dis2){
                swap(p[j],p[j+1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld %lld %lld \n",p[i].x,p[i].y,p[i].dis2);
    }
}