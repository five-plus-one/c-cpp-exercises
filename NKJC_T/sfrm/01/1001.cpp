#include<iostream>
using namespace std;
int gettype(char ch){
    if('0'<=ch&&ch<='9'){
        return 1;
    }else{
        return 0;
    }
}
void printchar(char ch,int n){
    for(int i=1;i<=n;i++){
        printf("%c",ch);
    }
    return;
}
void print2(char ch,int p1,int p2){
    if(p1==2 && gettype(ch)==0){
        ch-=32;
    }
    if(p1 == 3){
        ch = '*';
    }
    printchar(ch,p2);
}
void printbh(char from,char to,int p1,int p2,int p3){
    if(p3 ==1){
        for(char i = from+1;i <=to-1;i++){
            print2(i,p1,p2);
        }
    }else{
        for(char i = to-1;i >=from+1;i--){
            print2(i,p1,p2);
        }
    }
}
int main(){
    int p1,p2,p3;
    string str;
    scanf("%d%d%d",&p1,&p2,&p3);
    cin>>str;
    int n = str.length();
    for(int i=0;i<n;i++){
        if(str[i]=='-'&&i>0&&i<n-1&&str[i+1]!='-'&&str[i-1]!='-'&&gettype(str[i-1])==gettype(str[i+1])&&str[i+1]>str[i-1]){
            if(str[i+1]-str[i-1]>1){
                printbh(str[i-1],str[i+1],p1,p2,p3);
            }
            
        }else{
            printf("%c",str[i]);
        }
    }
}
