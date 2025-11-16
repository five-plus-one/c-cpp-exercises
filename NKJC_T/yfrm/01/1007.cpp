#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double c,d,p;
    cin>>c>>d;
    p=d/c*100;
    cout << fixed << setprecision(3) << p<<"%";
    return 0;
}