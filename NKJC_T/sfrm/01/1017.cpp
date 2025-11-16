#include<iostream>
using namespace std;
int n,map[10010],map2[10010];
int test(int a){
    for(int i=1;i<=n;i++){
        map2[i] = a;
        if(a > map[i]) return 0;
        a = map[i] - map2[i] - map2[i-1];
        if(i < n && (a<0||a>1)) return 0;
    }
    if(map[n]==map2[n-1]+map2[n]) return 1;
    else return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&map[i]);
    }
    int cnt = test(0)+test(1);
    printf("%d\n",cnt);
    return 0;
}