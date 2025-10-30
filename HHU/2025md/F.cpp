#include<iostream>
using namespace std;
const int N = 2 * 1e5 +10; 
struct foods{
    int t;
    int p;
    double r;
    char b;
};foods food[N];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&food[i].t);}
    for(int i=1;i<=n;i++){scanf("%d",&food[i].p);food[i].r = food[i].t*1.0/food[i].p;}
    for(int i=1;i<=n;i++){scanf(" %c",&food[i].b);}
    double maxr = food[1].r;
    int pos =1;
    for(int i=2;i<=n;i++){
        if(food[i].r > maxr){
            pos = i;
            maxr = food[i].r;
        }
    }
    // cout<<pos<<" "<<maxr<<endl;
    if(food[pos].b =='K'){
        printf("Crazy Thursday");
    }else {
        printf("Maimai yyds");
    }
    return 0;
}