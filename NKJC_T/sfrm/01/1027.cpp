#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N =25;
int n,m,k; //n 行数 m列数 k回合数
int map[N][N];
int sumnum,opnum,opnum2;
int lie[N];
int hangsum,ans,ansls;
int calopnum(int op,int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt+= (op>>i)&1;
    }
    return cnt;
}
void cal2(int op){ //根据对行的操作，维护出现有的x消除行的总和和列的剩余量
    hangsum = 0;
    memset(lie,0,sizeof(lie));
    for(int i=1;i<=n;i++){
        if((op>>(i-1))&1){ //如果这一行是操作行
            for(int j=1;j<=m;j++){
                hangsum+=map[i][j];
            }
        }else{ //这一行不是操作行，要维护出列
            for(int j=1;j<=m;j++){
                lie[j]+=map[i][j];
            }
        }
    }
    return;
}
bool comp(int a,int b){
    return a>b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    sumnum = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
            sumnum+=map[i][j];
        }
    }
    if(k>=n || k>=m){
        cout<<sumnum;
        return 0;
    }
    ans = 0;
    //核心思想：先枚举消除的行数，再贪心消除的列数
    for(int op=0;op<(1<<n);op++){
        
        opnum = calopnum(op,n);
        if(opnum > k || opnum + m < k) continue;
        opnum2 = k-opnum;
        cal2(op);
        sort(lie+1,lie+1+m,comp);
        // cout<<"op:"<<op<<endl;
        // for(int i=1;i<=m;i++){
        //     cout<<lie[i]<<" ";
        // }cout<<endl;
        ansls = hangsum;
        // cout<<"hangsum:"<<hangsum<<endl;
        for(int i=1;i<=opnum2;i++){
            ansls += lie[i];
            // cout<<lie[i]<<" ";
        }
        // cout<<endl;
        // cout<<"ansls:"<<ansls<<endl
        // <<"-------"<<endl;
        ans = max(ansls,ans);
    }
    cout<<ans;
    return 0;
}