#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Money{
    int m;
    int v;
    double vpm;
}money[110];
int t,n;
double value;
bool comp(Money a,Money b){
    return a.vpm > b.vpm;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>money[i].m>>money[i].v;
        money[i].vpm = money[i].v * 1.0 / money[i].m;
    }
    sort(money+1,money+1+n,comp);
    int i=1;value = 0;
    while(i<=n && t>0){
        if(t >= money[i].m){
            t -= money[i].m;
            value += money[i].v;
        }else{
            value += t * money[i].v * 1.0 / money[i].m;
            t = 0;
        }
        i++;
    }
    cout<<fixed<<setprecision(2)<<value<<endl;
    return 0;
}