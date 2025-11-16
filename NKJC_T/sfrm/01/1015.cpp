#include<iostream>
using namespace std;
string str;
int zmnum = 0,zmb[130],n;
int main(){
    cin>>str;
    n = str.length();
    int minlen = n+1;
    for(int left = 0,right = 0; left < n; left++){
        bool flag = true;
        if(zmnum == 26){
            flag = false;
        }
        while(right<n && flag){
            char ch = str[right];
            if(zmb[ch] == 0){
                zmnum++;
            }
            zmb[ch]++;
            if(zmnum == 26){
                flag = false;
            }
            right++;
        }
        //此时right本身就是多1的
        if(flag == false){
            // cout<<left<<" "<<right<<endl;
            int len = right - left;
            if(len < minlen) minlen = len;
        }
        char ch = str[left];
        zmb[ch]--;
        if(zmb[ch] == 0) zmnum --;
        // left++; 自增写在for逻辑里面，这里不需要自增
    }
    if(minlen == n+1){
        printf("-1\n");
    }else{
        printf("%d\n",minlen);
    }
}