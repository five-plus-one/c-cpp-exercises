//20260122 @5plus1 v2
// 哈希表的使用
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 2 * 1e5 + 10;
struct st{
    int id;
    int audio;
    int subtitle;
    int perfect;
    int good;
}film[N];
int scientist[N],n,m;
unordered_map <int,int> lang_count;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>scientist[i];
        lang_count[scientist[i]]++;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>film[i].audio;
        film[i].id = i;
    }
    for(int i=1;i<=m;i++){
        cin>>film[i].subtitle;
    }
    st maxfilm;
    maxfilm.perfect = -1;
    maxfilm.good = -1;
    for(int i=1;i<=m;i++){
        film[i].perfect = lang_count[film[i].audio];
        film[i].good = lang_count[film[i].subtitle];
        if(film[i].perfect > maxfilm.perfect || (film[i].perfect == maxfilm.perfect && film[i].good > maxfilm.good)){
            maxfilm = film[i];
        }
    }
    cout<<maxfilm.id<<endl;
    return 0;
}