#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N],n,q,qzh[40][N],l,r;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int op = 0; op <=30;op++){
            if(((a[i]>>op) & 1) == 1){
                qzh[op][i] = qzh[op][i-1]+1;
            }else{
                qzh[op][i] = qzh[op][i-1];
            }
        }
    }
    cin>>q;
    int cur;
    long long ans;
    for(int i=1;i<=q;i++){
        ans = 0;
        cin>>l>>r;
        int cnt = r-l+1; //总共的数字
        for(int i=0;i<=30;i++){
            if((qzh[i][r] - qzh[i][l-1])*2 <cnt){
                cur = 1;
            }else {
                cur = 0;
            }
            ans |=(cur<<i);
            // cout<<i<<" "<<cur<<" "<<qzh[i][r] - qzh[i][l-1]<<" "<<cnt<<" "<<ans<<" "<<endl;
        }
        cout<<ans<<endl;
    }
}