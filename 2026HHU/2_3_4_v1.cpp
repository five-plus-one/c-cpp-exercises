// 5plus1 20260122 贪心 v1
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5*1e4 + 10;
struct st{
    int a,b,id;
}cow[N];
int stall[N],num,n;
bool comp(st cow1,st cow2){
    return cow1.b < cow2.b;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>cow[i].a>>cow[i].b;
    }
    sort(cow,cow+n,comp);
    num = 0;
    for(int i=0;i<n;i++){
        int flag = 0;
        for(int j=1;j<=num;j++){
            if(stall[j] < cow[i].a){
                stall[j] = cow[i].b;flag = 1;
                cow[i].id = j;
                break;
            }
        }
        if(flag == 0){
            stall[++num] = cow[i].b;
            cow[i].id = num;
        }
    }
    cout<<num<<endl;
}