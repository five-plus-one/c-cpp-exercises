#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int T,n,L,R,U,D;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        L=R=U=D=0;
        char ch;
        for(int i=1;i<=n;i++){
            scanf(" %c",&ch);
            switch (ch)
            {
            case 'L':
                L++;
                break;
            case 'R':
                R++;
                break;
            case 'U':
                U++;
                break;
            case 'D':
                D++;
                break;
            }
        }
    int ans;
    // cout<<" "<<L<<R<<U<<D<<endl;
    if(L==0&&R==0){
        ans = max(U,D)+1;
    }
    else if(U==0&&D==0){
        ans = max(L,R)+1;
    }
    else if(U==D&&R==L){ 
        ans = 2*(U+R);
    }else{
        ans = U + D + R + L + 1;
    }
    printf("%d\n",ans);
    }

}