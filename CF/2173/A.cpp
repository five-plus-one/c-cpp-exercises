#include<iostream>
#include<string>
using namespace std;
int t,n,k,cur,ans,tmp;
int main(){
    scanf("%d",&t);
    ans = 0;
    while(t--){
        scanf("%d %d",&n,&k);
        tmp = 0;ans = 0;
        for(int i=1;i<=n;i++){
            scanf("%1d",&cur);
            // cout<<"cur:"<<cur<<" "<<tmp<<endl;
            if(cur == 0){
                if(tmp ==0) ans++;
                else tmp--;
            }
            else{
                tmp = k;
            }
        }
        printf("%d\n",ans);
    }
}