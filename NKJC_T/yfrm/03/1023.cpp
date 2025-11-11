#include<iostream>
using namespace std;
double gpa,sci,gpai,sctotal,gpatotal;
int n;
int main(){
    cin>>n;
    gpatotal = 0;
    sctotal = 0;
    for (int i = 1;i<=n;i++){
        cin>>gpai>>sci;
        gpatotal += sci*gpai;
        sctotal += sci;
    }
    gpa = gpatotal / sctotal;
    printf("%.1f",gpa);
    return 0;
}