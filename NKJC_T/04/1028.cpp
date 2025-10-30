#include<iostream>
using namespace std;
const int N = 5010;
struct student{
    int HH;
    int MM;
    int SS;
    int score;
};
student a[N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].HH,&a[i].MM,&a[i].SS);
        a[i].score = a[i].HH*10000+a[i].MM*100+a[i].SS;
    }
    for(int i=1;i<=n-1;i++){
        int minnum = a[i].score;
        int pos = i;
        for(int j=i+1;j<=n;j++){
            if(a[j].score<minnum){
                minnum = a[j].score;
                pos = j;
            }
        }
        swap(a[pos],a[i]);
    }
    for(int i = 1;i<=n;i++){
        printf("%d %d %d\n",a[i].HH,a[i].MM,a[i].SS);
    }
    return 0;
}