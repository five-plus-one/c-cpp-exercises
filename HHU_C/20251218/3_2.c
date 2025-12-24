#include<stdio.h>
int isprime(int N){
	int iN,res=1;
	for(iN=2;iN*iN<=N;iN++){
		if(N%iN==0)res=0;
	}
	return res;
}

int isH(int N){
	int sN=N,W,res=0;
	while(N>0){
		N/=10;
		W++;
	}
	N=sN;
	int K=0;
	if(W%2==0){
		W/=2;
		int iW;
		for(iW=0;iW<W;iW++){
			K+=K*10+N%10;
			N/=10;
		}
		if(N==K)res=1;
	}else{
		W/=2;
		int iW;
		for(iW=0;iW<W;iW++){
			K+=K*10+N%10;
			N/=10;
		}
		if(N/10==K)res=1;
	}
	return res;
}
int main(){
	int n,k,i;
	scanf("%d %d",&n,&k);
	if(n%2==0)i=n-1;
	else i=n;
	while(k>0){
		i+=2;
		if(isH(i)&&isprime(i)&&isprime(i+2)){
			printf("(%d,%d)\n",i,i+2);
			k--;
		}
	}
	return 0;
}