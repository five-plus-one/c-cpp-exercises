#include<iostream>
#include<algorithm>
using namespace std;
int n,ljs = 0,maxljs = 0;
double zqf=0;
string getpj(int n){
    if(n == 100000) return "Phi";
    else if(n >=96000) return "V";
    else if(n >=92000) return "S";
    else if(n>=88000) return "A";
    else if(n>=82000) return "B";
    else if(n>=70000) return "C";
    else return "F";
}
void solve(int casenum){
    if(casenum == 1){
        ljs++;
        zqf+=1;
        maxljs = max(maxljs,ljs);
    }else if(casenum ==2){
        ljs++;
        zqf+=0.65;
        maxljs = max(maxljs,ljs);
    }else{
        ljs = 0;
    }
}
int main(){
    
    ios::sync_with_stdio(false);
    cin>>n;
    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        if(str == "perfect"){
            solve(1);
        }else if(str =="miss"){
            solve(3);
        }else{
            int ms = 0;
            int n2 = str.length();
//            cout<<"   "<<n2<<endl;
            ms = 0;
            for(int i=0;i<n2-2;i++){
//            	cout<<str[i]<<"  ";
                if(str[i]!='-'){
                    ms=ms*10+(str[i]-'0');
//                    cout<<ms<<" ";
                }
            }
//            cout<<"   "<<ms<<endl;
            if(ms<=80) solve(1);
            else if(ms<=160) solve(2);
            else solve(3);
        }
    }
    int ans =  (zqf * 90000+ maxljs*1.0* 10000 ) / n ;
//    cout<<zqf<<" "<<maxljs<<endl; 
    cout<<ans<<" "<<getpj(ans);
}