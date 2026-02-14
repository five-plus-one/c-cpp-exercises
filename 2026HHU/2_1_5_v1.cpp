#include<iostream>
#include<algorithm>
using namespace std;
int n,time1,cnt;
const int N = 1e6+10;
struct Contest{
    int a;
    int b;
}contest[N];
bool comp(Contest x,Contest y){
    return x.b < y.b || (x.b == y.b && x.a > y.a);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>contest[i].a>>contest[i].b;
    }
    sort(contest+1,contest+1+n,comp);
    cnt = 0;time1 = 0;
    for(int i=1;i<=n;i++){
        if(contest[i].a >= time1){
            cnt ++;
            time1 = contest[i].b;
        }
    }
    cout<<cnt<<endl;

}