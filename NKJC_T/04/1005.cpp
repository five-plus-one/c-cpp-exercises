#include<iostream>
using namespace std;
int n, ni,lastn, last2n;
const int N = 110;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ni;
        last2n = lastn;
        lastn = ni;
    }
    if(n == 1){
        if(lastn == 15){
            printf("DOWN");
        }else if(lastn == 0){
            printf("UP");
        }else {
            printf("-1");
        }
    }else {
        if((lastn - last2n > 0 && lastn<15)||(lastn-last2n<0 && lastn==0)){
            printf("UP");
        }else{
            printf("DOWN");
        }
    }
}