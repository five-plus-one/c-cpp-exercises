//20260122 @5plus1 TLE v1
#include<iostream>
#include<algorithm>
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

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>scientist[i];
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
        film[i].good = 0;
        film[i].perfect = 0;
        for(int j=1;j<=n;j++){
            if(film[i].audio == scientist[j]) film[i].perfect++;
            else if(film[i].subtitle == scientist[j]) film[i].good++;
        }
        if(film[i].perfect > maxfilm.perfect || (film[i].perfect == maxfilm.perfect && film[i].good > maxfilm.good)){
            maxfilm = film[i];
        }
    }
    cout<<maxfilm.id<<endl;
    return 0;
}