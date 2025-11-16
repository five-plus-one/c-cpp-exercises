#include<iostream>
using namespace std;
int main(){
    int n,m,s,l,r;
    char a[120]={},c1,c2;
    scanf("%d %d",&n,&m);getchar();//换行符
    for(int i=1;i<=n;i++){
        a[i] = getchar();
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %c %c",&l,&r,&c1,&c2);
        for(int j=l;j<=r;j++){
            if(a[j] == c1){a[j] = c2;}
        }
    }
    for(int i=1;i<=n;i++){
        putchar(a[i]);
    }
    return 0;
}