// 设懒羊羊在队伍中的位置是 i（1 ≤ i ≤ n）
// 他前面的人数是 i-1，需要满足 i-1 ≥ a，即 i ≥ a+1
// 他后面的人数是 n-i，需要满足 n-i ≤ b，即 i ≥ n-b
// 所以 i 的下界是 max(a+1, n-b)，上界是 n
// 可行位置数 = n - max(a+1, n-b) + 1
#include<iostream>
using namespace std;
int a,b,n;
int main(){
    cin>>n>>a>>b;
    cout<<n-max(a+1,n-b)+1;
    return 0;
}