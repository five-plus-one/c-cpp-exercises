#include<iostream>
#include<string>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string s;
    getline(cin,s);
    int pos = s.find(':');
    string quote  = s.substr(pos + 1);
    string target = "not happy";
    string replacement = "happy";
    while((pos = quote.find(target))!= string::npos){
        quote.replace(pos,target.length(),replacement);
        pos += replacement.length();
    }
    cout << "gm:" << quote <<endl;
    return 0;
}