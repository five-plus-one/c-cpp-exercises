#include<bits/stdc++.h>
using namespace std;
struct BigInt {
    vector<int> v;
    BigInt(int n = 0) {
        if (n == 0) v.push_back(0);
        while (n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }
    }
    BigInt operator*(int x) const {
        BigInt res;
        res.v.clear();
        int carry = 0;
        for (int i = 0; i < v.size() || carry; i++) {
            long long current = carry;
            if (i < v.size()) current += (long long)v[i] * x;
            res.v.push_back(current % 10);
            carry = current / 10;
        }
        while (res.v.size() > 1 && res.v.back() == 0) res.v.pop_back();
        return res;
    }
    BigInt operator/(int x) const {
        BigInt res;
        res.v.resize(v.size());
        long long remainder = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            remainder = remainder * 10 + v[i];
            res.v[i] = remainder / x;
            remainder %= x;
        }
        while (res.v.size() > 1 && res.v.back() == 0) res.v.pop_back();
        return res;
    }
    bool operator<(const BigInt& b) const {
        if (v.size() != b.v.size()) return v.size() < b.v.size();
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] != b.v[i]) return v[i] < b.v[i];
        }
        return false;
    }
    void print() {
        for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
        cout << endl;
    }
};
int main(){
    BigInt a = 1;
    int  b = 114514;
    for(int i=1;i<=1e3;i++){
        a = a*b;
    }
    a.print();

    // int n;cin>>n;
    // int l,r;cin>>l>>r;
    // vector<pair<int,int>> a(n);
    // for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    // sort(a.begin(),a.end(),[](pair<int,int> a,pair<int,int> b){
    //     return a.first*a.second<b.first*b.second;});
    // BigInt ans=0,product=l;
    // for(int i=0;i<n;i++){
    //     ans=max(ans,product/a[i].second);
    //     product=product*a[i].first;
    // }
    // ans.print();
    // return 0;
    }

    


