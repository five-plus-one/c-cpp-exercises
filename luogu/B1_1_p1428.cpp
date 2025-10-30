#include<iostream>
using namespace std;
int main(){
    int a[101],n,i,j;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int count;
    for(i=0;i<n;i++){
        count=0;
        for(j=0;j<i;j++){
            if(a[j]<a[i]){
                count++;
            }
        }
        cout<<count<<" ";
    }
}