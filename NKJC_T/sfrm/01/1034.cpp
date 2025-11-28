#include<iostream>
using namespace std;
const int N = 1e5+10;
struct st{
    int opid;
    int t;
}op[N];
int n,m;
int test0[40],test1[40];
int testnum(int n2){
    for(int i=1;i<=n;i++){
        if(op[i].opid == 1){
            n2 &= op[i].t;
        }else if(op[i].opid == 2){
            n2 |= op[i].t;
        }else{
            n2 ^= op[i].t;
        }
    }
    return n2;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    string str;int t;
    for(int i=1;i<=n;i++){
        cin>>str>>t;
        if(str =="AND"){
            op[i].opid = 1;
        }else if(str == "OR"){
            op[i].opid = 2;
        }else{
            op[i].opid = 3;
        }
        op[i].t = t;
    }
    int res1 = testnum(0),
        res2 = testnum((1LL<<31) - 1);
    // cout<<"0"<<" "<<res1<<endl<<"1"<<" "<<res2<<endl;
    for(int i=0;i<=30;i++){
        test0[i] = ((res1>>i)&1);
        test1[i] = ((res2>>i)&1);
    }
    int ans = 0,cur,orinum=0;
    for(int i=30;i>=0;i--){
        if(((1LL<<i)|orinum) > m){
            cur = test0[i];
        }else{
            if(test1[i] > test0[i]){
                orinum|=((1LL<<i));
            }
            cur = max(test1[i],test0[i]);
        }
        ans |= (cur<<i);
    }
    // cout<<orinum<<endl;
    // cout<<testnum(orinum)<<endl;
    cout<<ans;

}