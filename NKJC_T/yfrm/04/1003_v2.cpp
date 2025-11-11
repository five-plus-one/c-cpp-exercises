#include<iostream>
using namespace std;
int n,k,m,a[110];

int getdawang(){
    int count=0,flag = -1;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            count++;
            flag = i;
        }
    }
    if(count == 1){
        return flag;
    }else if(count >1){
        return -1;
    }else {
        return -2;
    }
}

void next(){
    k++;
    if(k>n-1){
        k=0;
    }
}

void bs(){
    for(int i=0;i<m;i++){
        next();
        while(a[k]==1){
            next();
        }
    }
    a[k]=1;
}
int main(){
    cin>>n>>k>>m;
    k--;
    while(getdawang()==-1){
        bs();
        // cout<<"getdawang="<<getdawang()<<"指针指向"<<k<<endl;
    }
    cout<<getdawang();
}