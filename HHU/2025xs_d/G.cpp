#include<iostream>
using namespace std;
int n,m;
int cal1(int n,int m){
	if(n<m)return cal1(m,n);
	if(n%m ==0) return m;
	else return cal1(m,n%m);
}
void printnm(int n,int m){
	for(int i=1;i<=n;i++){
		printf("%d",m);
	}
	return;
}
void printab(int a,int b,int k,int type){
	for(int i=1;i<=a;i++){
		for(int j=1;j<=k;j++){
			for(int m = 1;m<=b;m++){
				printnm(j-1,1-type);
				printnm(1,type);
				printnm(k-j,1-type);
			}
			printf("\n");
		}
	}
}
int main(){
    scanf("%d %d",&n,&m);
    int k = cal1(n,m);
//    printf("%d",k);
    if(k<2){
    	printf("-1");
	}else{
		int a = n/k,b= m/k;
		int s = a*b;
		int minnum = s * k;
		int maxnum = n*m-minnum;
//		cout<<minnum<<endl;
		printf("%d %d\n",minnum,maxnum);
		printab(a,b,k,1);
		printab(a,b,k,0);
	}
    return 0;
}