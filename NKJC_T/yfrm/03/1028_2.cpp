#include<iostream>
using namespace std;
long long N,R,N2;
int list[32790],i;

void printnum(int x){
    if(x<10){
        cout<<x;
    }else {
        cout<<char(x-10+'A');
    }
}


int main(){
    cin>>N>>R;
    N2=N;
    i=0;
    if(N == 0){
        list[1]=0;
        i=1;
    }
    while(N!=0){
        i++;
        list[i] = N % (R);
        N /= R;
        if(list[i] < 0){
            list[i]-= R;
            N++;
        }
    }
    cout<<N2<<"=";
    for(;i>0;i--){
        printnum(list[i]);
    }
    cout<<"(base"<<R<<")";
    return 0;
}
