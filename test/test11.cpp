#include<bits/stdc++.h>
using namespace std;
map <string,int> st;
int main(){
    string s;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        st[s]++;
    }
    map<string,int>::iterator it;
    int maxn = 0;
    string str;
    for(it = st.begin();it!=st.end();it++){
        if(it->second >maxn){
            maxn = it->second;
            str = it->first;
        }
    }
    cout<<str;
    return 0;
}