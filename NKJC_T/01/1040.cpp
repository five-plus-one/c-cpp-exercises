// 答案始终是 n+1。

// 理由：

// 需要 p^k = n，p、k 为正整数。
// 取 k=1、p=n 则满足 n = n^1，且此时 p+k = n+1。
// 若 k≥2，则 p = n^(1/k) ≤ sqrt(n)，因此 p+k ≤ sqrt(n)+k < n+1（当 n≥2），不可能超过 n+1。
// 实现：读入 n，输出 n+1 即可。
#include<iostream>
using namespace std;
int main(){
    long long  n;
    cin>>n;
    cout<<n+1;
    return 0;
}