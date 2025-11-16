#include<iostream>
using namespace std;
int main(){
    int T,n;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&n);
        int cnt = 0;
        string str;
        for(int i=1;i<=n;i++){
            cin>>str;
            if(str.find("bnu16-")!=string::npos){
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}