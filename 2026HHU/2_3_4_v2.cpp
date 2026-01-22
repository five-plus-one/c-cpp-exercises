// 5plus1 20260122 v3
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;

struct st{
    int time;
    int delta;
} events[N];

int n, num;

bool comp(st events1,st events2){
    if (events1.time == events2.time) {
        // 时间相同时，先处理结束事件（delta=-1），再处理开始事件（delta=+1）
        return events1.delta < events2.delta;
    }
    return events1.time < events2.time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    num = 0;
    
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        // 开始事件
        num++;
        events[num].time = a;
        events[num].delta = 1;
        // 结束事件：注意用b+1
        num++;
        events[num].time = b + 1;
        events[num].delta = -1;
    }
    
    // 排序
    sort(events + 1, events + num + 1, comp);
    
    int cnt = 0, maxcnt = 0;
    int i = 1;
    
    while(i <= num) {
        int current_time = events[i].time;
        // 处理所有相同时间点的事件
        while(i <= num && events[i].time == current_time) {
            cnt += events[i].delta;
            i++;
        }
        // 在处理完同一时间点的所有事件后更新最大值
        maxcnt = max(maxcnt,cnt);
    }
    cout<<maxcnt<<endl;
    return 0;
}