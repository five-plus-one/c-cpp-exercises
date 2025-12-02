#include<iostream>
using namespace std;
using ll = long long;
string s;
ll ksm(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
        }
        a*=a;
        b>>=1;
    }
    return ans;
}
ll cal(ll a,int op,ll b){
    if(op == 1) return a+b;
    if(op == 2) return a-b;
    if(op == 3) return a*b;
    if(op == 4) return a/b;
    else return ksm(a,b);
}
ll solve(int l,int r){
    // cout<<"计算"<<l<<" "<<r<<endl;
    if(l>r) return 0;
    int pos1 = -1, pos2 = -1, pos3 = -1, matchnum = 0;
    for(int i=l;i<=r;i++){
        char cch = s[i];
        if(cch=='(') matchnum++;
        if(cch==')') matchnum--;
        if(matchnum == 0){
            if(cch == '+' || cch == '-') pos1 = i;
            if(cch == '*' || cch == '/') pos2 = i;
            if(cch == '^') pos3 = i;
        }
    }
    if(pos1 == -1 && pos2 == -1 && pos3 == -1){
        if(s[l]=='(' && s[r] ==')'){
            return solve(l+1,r-1);
        }else{
            int num = 0;
            for(int i=l;i<=r;i++){
                num = num*10 + (s[i]-'0');
            }
            return num;
        }
    }else{
        int pos,op;
        if(pos1!=-1){
            pos = pos1;
            if(s[pos]=='+') op = 1;
            else op = 2;
        }else if(pos2!=-1){
            pos = pos2;
            if(s[pos]=='*') op = 3;
            else op = 4;
        }else{
            pos = pos3;
            op = 5;
        }
        return cal(solve(l,pos-1),op,solve(pos+1,r));
    }
}
int main(){
    cin>>s;
    ll ans = solve(0,s.length()-1);
    cout<<ans;
}