#include<iostream>
#include<cmath>
using namespace std;
int T,j;
long long k,ans;

int main(){
    cin>>T;
    for(int i =1;i<=T;i++){
        cin>>k;
        j = 0;
        ans =0;
        while(k){
            ans +=(k & 1) * pow(3,j); 
            j++;
            k>>=1;
        }
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}
