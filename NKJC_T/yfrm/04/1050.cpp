#include<iostream>
using namespace std;
bool isend(int n1,int n2){
    while(n1){
        if(n1%10 != n2%10 || !n2){
            return 0;
        }
        n1/=10;n2/=10;
    }
    return 1;
}
int main(){
    int n,q,book[1010]={};
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&book[i]);
    }
    for(int i=1;i<=q;i++){
        int l,hm;
        scanf("%d%d",&l,&hm);
        bool find = false;
        int minhm = -1;
        for(int j=1;j<=n;j++){
            if(isend(hm,book[j])){
                if(minhm == -1){minhm = book[j];find = true;}
                else{
                    if(book[j]<minhm){
                        minhm = book[j];
                    }
                }
            }
        }
        printf("%d\n",minhm);
    }
}