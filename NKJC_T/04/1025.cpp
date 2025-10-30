#include<iostream>
using namespace std;
int map[11][11];
int numlist[11]={};
bool hf = true;
void qk(){
    for(int i=1;i<=9;i++){
        numlist[i] = 0;
    }
}
bool judgeline(int type,int n){
    qk();
    int tmpnum;
    for(int i=1;i<=9;i++){
        if(type == 1){tmpnum = map[n][i];}
        else if(type ==2){tmpnum = map[i][n];}

        if(numlist[tmpnum] == 1){return false;}
        else if(numlist[tmpnum] ==0){numlist[tmpnum] = 1;}
    }
    return true;

}
bool judgefk(int x,int y){
    qk();
    int tmpnum;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tmpnum = map[x+i][y+j];
            if(numlist[tmpnum] == 1){return false;}
            else if(numlist[tmpnum] == 0){numlist[tmpnum] = 1;}
        }
    }
    return true;
}

int main(){
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            scanf("%d",&map[i][j]);
        }
    }
    // cout<<judgeline(1,1)<<endl;

    hf = true;
    for(int i =1;i<=9;i++){

        if((!judgeline(1,i))||(!judgeline(2,i))){
            // cout<<i<<" "<<judgeline(1,i)<<" "<<judgeline(2,i)<<endl;
            hf = false;
        }
    }
    for(int i=1;i<9;i+=3){
        for(int j=1;j<9;j+=3){
            if(!judgefk(i,j)){
                hf = false;
            }
        }
    }
    if(hf){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;

}