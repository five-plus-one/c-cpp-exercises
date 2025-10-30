#include<iostream>
using namespace std;
bool hf = true;
string gs(string str){
    string str2 = str.substr(0,3);
    if(str2 == "133"||str2 == "149"||str2 == "153"||str2 == "173"||str2 == "177"||str2 == "180"||str2 == "181"||str2 == "189"||str2 == "199"){
        return "ChinaTelecom";
    }else if(str2 == "130"||str2 == "131"||str2 == "132"||str2 == "145"||str2 == "155"||str2 == "156"||str2 == "166"||str2 == "171"||str2 == "175"||str2 == "176"||str2 == "185"||str2 == "186"){
        return "ChinaUnicom";
    }else if(str2 == "134"||str2 == "135"||str2 == "136"||str2 == "137"||str2 == "138"||str2 == "139"||str2 == "147"||str2 == "150"||str2 == "151"||str2 == "152"||str2 == "157"||str2 == "158"||str2 == "159"||str2 == "172"||str2 == "178"||str2 == "182"||str2 == "183"||str2 == "184"||str2 == "187"||str2 == "188"||str2 == "198"){
        return "ChinaMobile";
    }else{
        hf = false;
        return "NoNoNo";
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        string str;
        hf = true;
        cin>>str;
        int n =str.length();
        if(n!=11){
            hf = false;
        }else{
            for(int i=0;i<n;i++){
                if(str[i]>'9'||str[i]<'0'){
                    hf = false;
                }
            }
        }
        if(hf){
            cout<<gs(str)<<endl;
        }else{
            cout<<"NoNoNo"<<endl;
        }
    }
}