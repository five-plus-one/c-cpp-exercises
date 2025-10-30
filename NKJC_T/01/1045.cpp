//v1
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double g = 10;
double H,s1,V,L,K,n,l1,l2,t1,t2;
int d1,d2,ans;
int main(){
    cin>>H>>s1>>V>>L>>K>>n;
    t1=sqrt(2*H/g);
    l1=s1-t1*V;
    t2=sqrt(2*(H-K)/g);
    l2=s1+L-t2*V;
    d1=max(0,min(int(ceil(l1)),int(n-1)));
    d2=min(int(n-1),int(l2));
    // cout<<d1<<" "<<d2<<" ";
    if(d1>d2){
        ans = 0;
    }else {
        ans = d2-d1+1;
    }
    cout<<ans;

}