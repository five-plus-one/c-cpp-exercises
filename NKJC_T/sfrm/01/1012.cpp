#include<iostream>
using namespace std;
const int N = 8010;
int map[N][N],f[N][N],r,n,xi,yi,vi,maxx=0,maxy=0;
void generatef(){
    for(int i=1;i<=maxx+r+1;i++){
        for(int j=1;j<=maxy+r+1;j++){
            f[i][j] = f[i-1][j]+f[i][j-1]+map[i][j]-f[i-1][j-1]; //二维前缀和
        }
    }
}
int calvalue(int a,int b,int c,int d){
    return f[c][d] - f[c][b-1] - f[a-1][d] + f[a-1][b-1];
}
void printmap(){
    cout<<endl<<"----"<<endl;
    for(int i=1;i<=maxx;i++){
        for(int j=1;j<=maxy;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;        
    }
    cout<<endl<<"----"<<endl;
}
void printqzh(){
    cout<<endl<<"----"<<endl;
    for(int i=1;i<=maxx;i++){
        for(int j=1;j<=maxy;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;        
    }
    cout<<endl<<"----"<<endl;
}
int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&xi,&yi,&vi);
        xi++;yi++; //偏移1
        map[xi][yi]+=vi;
        maxx=max(xi,maxx);
        maxy=max(yi,maxy);
    }
    generatef();
    // printmap();
    // printqzh();
    int maxvalue = 0,currentvalue = 0;
    for(int i=1;i<=maxx;i++){
        for(int j=1;j<=maxy;j++){
            currentvalue  = calvalue(i,j,i+r-1,j+r-1);
            if(currentvalue > maxvalue){maxvalue = currentvalue;
                // cout<<i<<" "<<j<<" "<<i+r-1<<" "<<j+r-1<<" "<<currentvalue<<endl;
            }       
        }
    }
    printf("%d\n",maxvalue);
    return 0;
}