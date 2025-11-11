#include<iostream>
using namespace std;
int n;
void blank(int n){
    for (int i=1;i<=n;i++) cout<<" ";
}

int main(){
//    cout<<int('A'); A - 65
    char ch;
    int n,j;
    cin>>ch;
    n = int(ch)-64;
    for(int i = 1;i<= n;i++){
        blank(n-i);
        for (j=1;j<=i;j++){
            cout<<char(j+64);
        }
        for(j = i-1;j>0;j--){
            cout<<char(j+64);
        }
        cout<<endl;
    }
    return 0;
}