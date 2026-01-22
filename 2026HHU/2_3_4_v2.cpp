// 5plus1 20260122 v2 差分
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
struct st{
    int events,delta;
}events[N];
int a,b,n,num;
bool comp(st events1,st events2){
    return events1.events < events2.events;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    num =0;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        events[++num].events = a;
        events[num].delta =1;
        events[++num].events = b+1;
        events[num].delta =-1;
    }
    sort(events+1,events+1+num,comp);
    int cnt = 0,maxcnt = 0;
    int i=1;
    while(i<=num){
        do{
            cnt+=events[i].delta;
            i++;
        } while(i<=num && events[i].events == events[i+1].events);
        maxcnt = max(cnt,maxcnt);
        
    }
    cout<<maxcnt<<endl;
}