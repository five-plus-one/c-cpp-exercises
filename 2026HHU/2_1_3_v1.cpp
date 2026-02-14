#include<iostream>
#include<string>
#include<algorithm>
// 考虑类似sort函数的comp，对于s1,s2,当s1应该排在前面的时候，应该保证s1s2拼接>s2s1拼接
// 进一步的，可以考虑使用字符串拼接直接比较字典序，避开繁琐的数字处理
using namespace std;
string num[30];
int n;
bool comp(string num1,string num2){
    string res1 = num1 +num2;
    string res2 = num2 + num1;
    return res1 > res2;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+1+n,comp);
    for(int i=1;i<=n;i++){
        cout<<num[i];
    }
    cout<<endl;
}