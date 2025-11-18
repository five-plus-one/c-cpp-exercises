#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    int n; 
    map<string,int> students;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        students[str] = 1;
    }
    for(int i=1;i<=n-2;i++){
        cin>>str;
        students[str] = 0;
    }
    for(map<string,int>::iterator it=students.begin();it!=students.end();it++){
        if(it->second>0){
            cout<<(it->first)<<endl;
        }
    }
}