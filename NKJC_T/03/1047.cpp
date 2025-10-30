#include<iostream>
using namespace std;
bool flag;
int m,k,g,p,count=0,num;
int main(){
    flag = true;
    cin>>m>>k>>g>>p;
    while(flag){
        flag = false;
        if(m>0&&m/p>0){
            flag = true;
            num=m/p;
            count+=num;
            k+=num;
            g+=num;
            m-=num*p;
        }else if(g>=4){
            flag = true;
            num = g/4;
            count+=num;
            g-=num*4;
            g+=num;
            k+=num;
        }else if(k>=2){
            flag = true;
            num = k/2;
            count+=num;
            k-=num*2;
            g+=num;
            k+=num;
        }
    }
    cout<<count;
}