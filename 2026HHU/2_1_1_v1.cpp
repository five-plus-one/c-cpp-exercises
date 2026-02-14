//5plus1 20260122 v2
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
using ll = long long;
const int N = 1e3 + 10;
struct Person{
    int id;
    int t;
}person[N];
int n;
ll totaltime;
bool comp(Person a,Person b){
    return (a.t < b.t) || (a.t == b.t && a.id < b.id);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>person[i].t;
        person[i].id = i;
    }
    sort(person+1,person+1+n,comp);
    totaltime = 0;
    for(int i=1;i<=n;i++){
        cout<<person[i].id<<' ';
        totaltime += ( n - i ) * person[i].t;
    }
    cout<<endl<<fixed<<setprecision(2)<<(totaltime * 1.0 / n)<<endl;
    return 0;
}