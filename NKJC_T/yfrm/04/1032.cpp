#include<iostream>
using namespace std;
struct student{
    int ch;
    int ma;
    int en;
    int to;
    int sn;
};
student a[310];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].ch,&a[i].ma,&a[i].en);
        a[i].to = a[i].ch + a[i].ma + a[i].en;
        a[i].sn = i;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            if(!(a[j].to > a[j+1].to || (a[j].to == a[j+1].to && a[j].ch >a[j+1].ch) || (a[j].to == a[j+1].to && a[j].ch == a[j+1].ch && a[j].sn< a[j+1].sn))){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=5;i++){
        printf("%d %d\n",a[i].sn,a[i].to);
    }
    return 0;
}