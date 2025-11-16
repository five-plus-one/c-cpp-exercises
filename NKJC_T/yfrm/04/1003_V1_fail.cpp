#include<iostream>
using namespace std;
int n,k,m,a[110];

int getdw(){
    bool flag = false;
    int dw=-2;
    for(int i=0;i<=n-1;i++){
        if(a[i]!=1 && flag == false){
            dw=i;flag=true;
        }else if(a[i]!=1 && flag == true){
            dw=-1;
        }
    }
    return dw;
}
int main(){
    cin>>n>>k>>m;
    k=k-1;
    while(getdw()!=-1){
        for(int i=1;i<=m;i++){
            k++;
            if(k>n-1){
                k-=n;
            }  
            while(a[k]==1){
                k++;
                if(k>n-1){
                    k-=n;
                }  
            }
             
        }
        
        a[k]=1;
    }
    cout<<getdw();
    return 0;
}