#include<iostream>
using namespace std;
const int N = 2010;
int n,a[N],T;
int zsnum(int n){
    int cnt=0;
    for(int i=2;i*i<n;i++){
        for(int j=2;j*i<=n;j++){
            a[j*i] = 1;
        }
    }
    for(int i=2;i<=n;i++){
        cnt+=1-a[i];
    }

    return cnt;
}
int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        int n;
        scanf("%d",&n);
        printf("%d\n",zsnum(n));
    }
}