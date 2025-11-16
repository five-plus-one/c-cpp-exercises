#include<iostream>
using namespace std;
int getweight(string s){
    if(s =="elephant"){
        return 4;
    }else if(s == "tiger"){
        return 3;
    }else if(s == "cat"){
        return 2;
    }else if(s == "mouse"){
        return 1;
    }
    return 0;
}
int judge(int w1,int w2){
    if(abs(w1-w2)==3){
        return -(w1-w2)/(abs(w1-w2));
    }else if(abs(w1-w2)==1){
        return (w1-w2)/(abs(w1-w2));
    }else
    {return 0;}
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    int w1=getweight(s1),w2=getweight(s2);
    int ans = judge(w1,w2);
    if(ans == 1){
        printf("win");
    }else if(ans == 0){
        printf("tie");
    }else if(ans == -1){
        printf("lose");
    }
    
}