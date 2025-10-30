#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    stack<char> st;
    cin>>str;
    int n =str.length();
    for(int i=0;i<n;i++){
        if(str[i]=='A'){
            st.push('A');
        }else{
            st.pop();
        }
    }
    if(st.empty()){
        printf("YES");
    }else {
        printf("NO");
    }
}