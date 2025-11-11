#include<iostream>
using namespace std;

const int N = 5010;
int n,a[N]={0};
bool judge(int num,int n){
    for(int i=1;i<n;i++){
        if(a[i]==num){
            return false;
        }
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(judge(a[i],i)){
            printf("%d ",a[i]);
        }
    }
}