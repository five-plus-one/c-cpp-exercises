#include<bits/stdc++.h>
using namespace std;
long long  A,B,C,D,a,b,c,d,e,ans;
int main(){

    cin>>A>>B>>C>>D>>a>>b>>c>>d>>e;
    if(A>=520){
        ans = 520*a;
    }else if(B>=520){
        ans = A*a+(520-A)*b;
    }else if(C>=520){
        ans = A*a+(B-A)*b+(520-B)*c;
    }else if(D>=520){
        ans = A*a + (B-A) *b +(C-B) * c +(520-C)*d;
    }else{
    ans=A*a+(B-A)*b+(C-B)*c+(D-C)*d+(520-D)*e;}
    cout<<ans;
    return 0;
}