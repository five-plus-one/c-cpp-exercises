#include<iostream>
using namespace std;
int main(){
    char dic[130]={};
    string sj,sy,str;
    cin>>sj;cin>>sy;cin>>str;
    bool iserror = false;
    int n1 = sj.length();
    if(n1 !=sy.length()){iserror = true;}
    for(int i=0;i<n1;i++){
        char m = sj[i];
        char y = sy[i];
        if(dic[m]<'A' || dic[m]>'Z'){
            dic[m]=y;
        }else if(dic[m] != y){
            iserror = true;
        }
    }
    for(int i='A';i<='Z';i++){
        if(dic[i]<'A' || dic[i]>'Z'){
            iserror = true;
        }
    }
    if(iserror){
        cout<<"Failed"<<endl;
        return 0;
    }
    int strl = str.length();
    for(int i=0;i<strl;i++){
        printf("%c",dic[str[i]]);
    }
}