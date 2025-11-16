#include<iostream>
using namespace std;
const int N = 120;
int n,dx[N*N],dy[N*N];
char map[N][N];
char ch;
int X;int Y;bool hf;
void getdd(int x1,int y1,int x2,int y2,int num){
    double xm = (x1+x2)/2.0;
    double ym = (y1+y2)/2.0;
    double xc = (x1-x2)/2.0;
    double yc = (y1-y2)/2.0;
    double Xl,Yl;
    if(num ==1){
        Xl = xm - yc;
        Yl = ym + xc;
    }else{
        Xl = xm + yc;
        Yl = ym - xc;
    }
    if((int)Xl == Xl && (int)Yl == Yl && Xl>0 &&Xl<=n &&Yl>0 &&Yl<=n){
        hf = true;
        X = (int)Xl;
        Y = (int)Yl;
    }else{
        hf = false;
    }
}
double getlengthcompare(int x1,int y1,int x2,int y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
int main(){
    scanf("%d",&n);
    int m = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %c",&ch);
            map[i][j] = ch;
            if(ch == '#'){
                m++;
                dx[m] = i;
                dy[m] = j;
            }
        }
    }
    int maxi = -1;
    int maxj = -1;
    int maxlengthcomp = -1;
    for(int i=1;i<=m-1;i++){
        int x1 = dx[i],y1 = dy[i];
        for(int j=i+1;j<=m;j++){
            int x2 = dx[j],y2 = dy[j];
            getdd(x1,y1,x2,y2,1);
            if(hf == false){
                continue;
            }
            if(map[X][Y] == '*'){
                continue;
            }
            getdd(x1,y1,x2,y2,2);
            if(hf == false){
                continue;
            }
            if(map[X][Y] == '*'){
                continue;
            }
            if(maxlengthcomp == -1 || (maxlengthcomp!=-1 && getlengthcompare(x1,y1,x2,y2)>maxlengthcomp)){
                maxi = i;maxj = j;
                maxlengthcomp = getlengthcompare(x1,y1,x2,y2);
            }
        }
    }
    printf("%d %d\n",dx[maxi],dy[maxi]);
    getdd(dx[maxi],dy[maxi],dx[maxj],dy[maxj],1);
    printf("%d %d\n",X,Y);
    getdd(dx[maxi],dy[maxi],dx[maxj],dy[maxj],2);
    printf("%d %d\n",X,Y);
    printf("%d %d\n",dx[maxj],dy[maxj]);


}