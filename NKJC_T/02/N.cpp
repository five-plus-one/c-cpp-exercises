#include<iostream>
using namespace std;
int maxnum=0;

void testnum(int x){
    if(x>maxnum){
        maxnum =x;
    }
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    testnum(a+b+c);
    testnum(a*b*c);
    testnum(a*(b+c));
    testnum((a+b)*c);
    cout<<maxnum;
    return 0;
}