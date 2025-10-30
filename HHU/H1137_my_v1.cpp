#include<iostream>
#include<cstdio>
using namespace std;
char a[5];
char b[]={'H','H','U','1','0','8'};
void nextchar(){
    char ch;
    scanf("%1c",&ch);
    for(int i=0;i<=4;i++){
        a[i]=a[i+1];
    }
    a[5]=ch;
}

bool issame(){
    bool flag = true;
    for(int i=0;i<=5;i++){
        if(a[i]!=b[i]){
            flag = false;
        }
    }
    return flag;
}

int main(){
    char ch=' ';
    while(ch!=EOF){
        
        nextchar();
        // cout<<"A:"<<a<<endl;
        // cout<<"B:"<<b<<endl;
        if(issame()){
            cout<<"HappyBirthday";
            for(int i=1;i<=5;i++){
                nextchar();
            }
        }else{
            cout<<a[0];
        }
    }
    
    return 0;
}