#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[10] = {0,2,1,3,4,8,7,6,5};
    sort(a+1,a+7);

    for(int i=1;i<=6;i++){
        cout<<a[i]<<endl;
    }
}