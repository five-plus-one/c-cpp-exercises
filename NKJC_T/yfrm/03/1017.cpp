#include<iostream>
using namespace std;
long long n,i;
//我一开始忘了“包含4”的判断，直接WA了
bool has4(long long n){
    bool status=false;
    while(n){
        if(n%10==4){
            status = true;
        }
        n=n/10;
    }
    return status;
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++){
        if(i%4 !=0 && !(has4(i))){
            cout<<i<<endl;
        }
    }
    return 0;
}