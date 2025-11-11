#include<iostream>
using namespace std;
int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    if(a>b){swap(a,b);}
    if(b>c){swap(b,c);}
    if(a>b){swap(a,b);}
cout<<"The maximum number is : "<<c<<endl
    <<"The minimum number is : "<<a;
    return 0;
}