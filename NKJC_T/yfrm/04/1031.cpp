#include<iostream>
using namespace std;
int n,m;
struct xs{
    int k;
    int s;
};
xs a[5010];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].k,&a[i].s);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            if(!(a[j].s>a[j+1].s || (a[j].s==a[j+1].s && a[j].k<a[j+1].k))){
                swap(a[j],a[j+1]);
            }
        }
    }
    m = int(m*1.5);
    while(a[m+1].s == a[m].s){
        m++;
    }
    printf("%d %d\n",a[m].s,m);
    for(int i=1;i<=m;i++){
        printf("%d %d\n",a[i].k,a[i].s);
    }
}