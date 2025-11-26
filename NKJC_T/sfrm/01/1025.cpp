#include<iostream>
using namespace std;
int T,m,s,x,y;
void printn(int n,int num){ 
    for(int i=1;i<=n;i++){
        cout<<num;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T--){
        cin>>m>>s;
        if(s==0 && m == 1){
            cout<<"0 0"<<endl;
            continue;
        }
        if(s==0 || s > m *9){
            cout<<"-1"<<endl;
            continue;
        }
        //最小数
        if((m-1)*9<=s-1){ //最高位不能自由支配
            cout<<s-(m-1)*9;
            printn(m-1,9);
        }else{ //最高位可以支配
            cout<<1; 
            int num1 = (s-1) / 9; //一共有多少位9
            int num2 = (s-1) - num1 *9; //前面的一位
            if(num2 == 0){
                printn(m-1-num1,0);
                printn(num1,9);
            }else{
                printn(m-1-num1-1,0);
                cout<<num2;
                printn(num1,9);
            }
        }
        cout<<" ";
        //最大数
        int num1 = s/9;
        int num2 = s-num1*9;
        if(num2 == 0){
            printn(num1,9);
            printn(m-num1,0);
        }else{
            printn(num1,9);
            cout<<num2;
            printn(m-num1-1,0);
        }
        cout<<endl;
    }
}
    