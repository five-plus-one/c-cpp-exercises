#include<iostream>
using namespace std;
long long n,a=0,b=0,c=0;
int m;
bool can;
void judge(){
    if(a<0 || b<0 || c<0){
        can = false;
    }
}
void zl(int money){
    if(money == 25){
        a++;
    }else if(money == 50){
        a--;b++;
    }else {
        a--;b--;c++;
    }
    judge();
}
int main(){
    cin>>n;
    can = true;
    for(int i=1;i<=n;i++){
        cin>>m;
        zl(m);
        // cout<<can<<endl;
    }
    if(can){
        cout<<"YES";
    }else {
        cout<<"NO";
    }
}