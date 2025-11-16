#include<iostream>
#include<string>
using namespace std;
bool isequal(string str1,string str2){
    if(str1 == str2){return true;}
    if(str1.length()!=str2.length()){return false;}
    int n = str1.length();
    for(int i=0;i<n;i++){
        if(!(str1[i] == str2[i] || abs(str1[i] - str2[i]) == 32)){
            return false;
        }
    }
    return true;
}
int main(){
    string str1,str2="";
    cin>>str1;
    int pos_f = -1,pos_i = 0;
    int cnt = 0;
    // while(cin>>str2){
    //     if(isequal(str1,str2)){
    //         cnt++;
    //         if(cnt == 1){
    //             pos_f = pos_i;
    //         }
    //     }
    //     pos_i+=str2.length();
    //     pos_i++;
    // }
    char ch=' ';
    str2 = "";
    int cnt2 = 0; //单词字数
    getchar(); // 换行符
    while(ch!=EOF){
        ch = getchar();
        if(ch==' ' || ch == EOF){
            // cout<<str2<<' '<<str2.length()<<endl;
            if(isequal(str1,str2)){
                cnt++;
                if(cnt == 1){
                    pos_f = pos_i-cnt2;
                }
            }
            cnt2 = 0;
            str2 = "";
        }else{
            str2+=ch;
            cnt2++;
        }
        pos_i++;
    }
    if(cnt ==0){cout<<-1;}else{
        cout<<cnt<<" "<<pos_f;
    }
}