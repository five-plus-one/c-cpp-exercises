// 5plus1 2026/1/19 v2
#include<iostream>
using namespace std;
const int N = 210;
int score_a = 0, score_b = 0;
int n,na,nb,ia,ib,a[N],b[N],res;
const int result[5][5]={
    {0,-1,1,1,-1},
    {-2,0,-1,1,-1},
    {-2,-2,0,-1,1},
    {-2,-2,-2,0,1},
    {-2,-2,-2,-2,0}
};
int getresult(int a,int b){ //a对b
    if(a>b) return -1 * getresult(b,a);
    else return result[a][b];
}
void next(){
    ia++;ib++;
    if(ia >= na) ia = 0;
    if(ib >= nb) ib = 0;
    return;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++) cin>>a[i];
    for(int i=0;i<nb;i++) cin>>b[i];
    ia=ib=0;
    while(n--){
        res = getresult(a[ia],b[ib]);
        if(res == 1) score_a++;
        if(res == -1) score_b++;
        next();
    }
    cout<<score_a<<' '<<score_b<<endl;
}