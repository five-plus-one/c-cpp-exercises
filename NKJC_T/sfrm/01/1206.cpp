#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e3 + 10;
struct st{
    int num;
    int cnt;
}hang[N],lie[N];
int n,m, //n行m列
    k,l, //k横l竖
    d, //对数
    xi,yi,pi,qi; //(xi,yi)与(pi,qi)
bool comp1(st a,st b){
    return (a.cnt>b.cnt) || (a.cnt == b.cnt && a.num < b.num); 
}
bool comp2(st a,st b){
    return a.num < b.num;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k>>l>>d;
    //初始化num
    for(int i=1;i<=n;i++){
        hang[i].num = i;
    }
    for(int i=1;i<=m;i++){
        lie[i].num = i ;
    }
    for(int i=1;i<=d;i++){
        cin>>xi>>yi>>pi>>qi;
        if(xi == pi) lie[min(yi,qi)].cnt++;
        else hang[min(xi,pi)].cnt++;
    }
    sort(hang+1,hang+1+n,comp1);
    sort(hang+1,hang+1+k,comp2);
    sort(lie+1,lie+m+1,comp1);
    sort(lie+1,lie+1+l,comp2);
    // cout<<"----"<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<hang[i].num<<" "<<hang[i].cnt<<endl;
    // }
    // cout<<"----"<<endl;
    // for(int i=1;i<=m;i++){
    //     cout<<lie[i].num<<" "<<lie[i].cnt<<endl;
    // }
    // cout<<"----"<<endl;
    for(int i=1;i<=k;i++){
        cout<<hang[i].num<<" ";
    }
    cout<<endl;
    for(int i=1;i<=l;i++){
        cout<<lie[i].num<<" ";
    }
    return 0;
}