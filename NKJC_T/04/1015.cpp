#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2010;
int n,m,a[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+m;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+m+1);
    for(int i=1;i<=m+n;i++){
        printf("%d ",a[i]);
    }
}