#include<iostream>
#include<algorithm>
using namespace std;
int dp[30][30],n;
int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int k = 0 ; k< n; k++){
        int w,v; //大小，美味程度
        cin >> w >> v;
        for(int i=10; i >= 0; i--){
            for(int j=12;j>=0;j--){
                if(i >= w){
                    dp[i][j] = max(dp[i][j],dp[i-w][j] + v);
                }
                if(j >= w){
                    dp[i][j] = max(dp[i][j],dp[i][j-w] + v);
                }
            }
        }
    }
    cout << dp[10][12] << endl;
    return 0;
}