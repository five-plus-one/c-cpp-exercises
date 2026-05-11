#include<iostream>
using namespace std;
using ll = long long;
int main(){
    ll T,n,punishment = 0,choice;
    ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
    cin >> n >> T;
    while(T--){
        cin >> choice;
        if(choice == 0){
            punishment = 0;
            n += 3;
        }else{
            punishment++;
            n -= punishment;
        }
    }
    cout << n << endl;

}