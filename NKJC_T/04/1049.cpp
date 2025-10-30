#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char grid[10][10] = {
    {},
    {'0','0','1','2','3','4','5'},
    {'0','6','7','8','9','A','B'},
    {'0','C','D','E','F','G','H'},
    {'0','I','J','K','L','M','N'},
    {'0','O','P','Q','R','S','T'},
    {'0','U','V','W','X','Y','Z'}
};
struct cnt2 {int id;int cnt;};
int calnum(char ch,string str){
    int strl = str.length();
    int tmpcnt = 0;
    for(int i=0;i<strl;i++){
        if(str[i] == ch){
            tmpcnt++;
        }
    }
    return tmpcnt;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        cnt2 hcnt[10]={};cnt2 lcnt[10]={};
        string S;
        cin>>S;
        for(int i=1;i<=6;i++){
            int cntcal1 = 0,cntcal2=0;
            for(int j=1;j<=6;j++){
                cntcal1+=calnum(grid[i][j],S);
                cntcal2+=calnum(grid[j][i],S);
            }
            hcnt[i].cnt=cntcal1;
            hcnt[i].id = i;
            lcnt[i].id =i;
            lcnt[i].cnt=cntcal2;
        }
        // sort(hcnt+1,hcnt+7);
        // sort(lcnt+1,lcnt+7);
        sort(hcnt+1, hcnt+7, [](const cnt2& a, const cnt2& b) {
        return a.cnt < b.cnt;
    });
    sort(lcnt+1, lcnt+7, [](const cnt2& a, const cnt2& b) {
        return a.cnt < b.cnt;
    });
        int maxhcnt = hcnt[6].cnt;
        int maxlcnt = lcnt[6].cnt;
        // for(int i=1;i<=6;i++){
        //     cout<<hcnt[i]<<"  "<<lcnt[i]<<endl;
        // }
        // cout<<"----"<<endl;
        for(int i=1;i<=6;i++){
            int k = 1;
            while(hcnt[k].id != i){k++;}
            if(hcnt[k].cnt == maxhcnt){
                for(int j=1;j<=6;j++){
                    int m =1;
                    while(lcnt[m].id !=j){m++;}
                    if(lcnt[m].cnt == maxlcnt){
                        printf("%c",grid[i][j]);
                    }
                }
            }
        }
        printf("\n");
    }   
}
