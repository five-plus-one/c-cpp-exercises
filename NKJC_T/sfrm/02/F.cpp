#include<iostream>
using namespace std;
string str;
int n;
char solve(int l,int r){
    char res;
    if(l == r){
        if(str[l]=='0') res = 'B';
        else res = 'I';
        cout<<res;
        return res;
    }else{
        int mid = (l+r)/2;
        char a = solve(l,mid);
        char b = solve(mid+1,r);
        if(a == b &&(a=='B' || a =='I')){
            res = a;
            cout<<res;
            return res;
        }else{
            res = 'F';
            cout<<res;
            return res;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    cin>>str;
    solve(0,(1LL<<n)-1);
    return 0;
}