#include<iostream>
using namespace std;
bool isrun(int y){
    return((y%4==0&&y%100!=0)||y%400==0);
}
int getdays(int y,int m){
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        return 31;
    }else if(m!=2){
        return 30;
    }else{
        return 28+isrun(y);
    }
}
int getdx(int y1,int m1,int d1,int y2,int m2,int d2){
    if(y1==y2&&m1==m2&&d1==d2){
        return 0;
    }else if(y1*10000+m1*100+d1<y2*10000+m2*100+d2){
        return 1;
    }else{
        return -1;
    }
}
bool qj(int y,int m,int d,int y1,int m1,int d1,int y2,int m2,int d2){
    return(getdx(y,m,d,y1,m1,d1)!=1&&getdx(y,m,d,y2,m2,d2)!=-1);
}
bool ishf(int y,int m,int d){
    return (m>0 && m<=12 && d>0 && d<=getdays(y,m));
}
int main(){
    int Y1,M1,D1,Y2,M2,D2,Y,M,D;
    scanf("%4d%2d%2d %4d%2d%2d",&Y1,&M1,&D1,&Y2,&M2,&D2);
    // cout<<Y1<<" "<<M1<<" "<<D1<<endl;
    // cout<<Y2<<" "<<M2<<" "<<D2<<endl;
    int cnt = 0;
    for(Y = Y1;Y<=Y2;Y++){
        M = Y%10 *10 + Y/10%10;
        D = Y/100%10*10+Y/1000%10;
        cnt+=(ishf(Y,M,D) && qj(Y,M,D,Y1,M1,D1,Y2,M2,D2));
    }
    printf("%d",cnt);
}