#include<iostream>
using namespace std;
long long N,R,N2;
int list[32790],i;

void printnum(int x){
    switch (x)
    {
    case 10:
        cout<<"A";
        break;
    case 11:
        cout<<"B";
        break;
    case 12:
        cout<<"C";
        break;
    case 13:
        cout<<"D";
        break;
    case 14:
        cout<<"E";
        break;
    case 15:
        cout<<"F";
        break;
    case 16:
        cout<<"G";
        break;
    case 17:
        cout<<"H";
        break;
    case 18:
        cout<<"I";
        break;
    case 19:
        cout<<"J";
        break;
    case 20:
        cout<<"K";
        break;
    
    default:
        cout<<x;
        break;
    }
}


int main(){
    cin>>N>>R;
    N2=N;
    i=0;
    if(N==0){
        cout<<"0=0";
    }else{
    while(N!=0){
       i++;
       list[i] = N % R;
       N /= R; 
       if(list[i]<0){
            list[i]-=R;
            N++;
       }
    }
    cout<<N2<<"=";
    for(;i>0;i--){
        printnum(list[i]);
    }}
    cout<<"(base"<<R<<")";
    return 0;

}
