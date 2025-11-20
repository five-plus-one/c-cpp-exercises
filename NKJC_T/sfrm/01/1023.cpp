#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
const int N = 1e6+10;
int nextc[40][N],lastc[40],n,q,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(lastc,-1,sizeof(lastc));
    string s,t;
    cin>>s;
    n = s.length();
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++){
            nextc[j][i] = lastc[j];
            // cout<<lastc[j]<<" ";
        }
        // cout<<endl;
        lastc[s[i]-'a'] = i;
        // cout<<s[i]-'a'<<" "<<i<<endl;
    }
    // for(int i=0;i<26;i++){
    //     cout<<lastc[i]<<endl;
    // }


    cin>>q;
    while(q--){
        cin>>t;
        m = t.length();
        int pos = 0;
        bool flag = false;
        for(int i=0;i<m;i++){
            pos = nextc[t[i]-'a'][pos];
            // cout<<pos<<endl;
            if(pos == -1 && i<m){flag = true; break;}
        }
        if(flag){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
        }
    }
}