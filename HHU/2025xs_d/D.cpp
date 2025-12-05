#include<iostream>
#include<algorithm>
using namespace std;
long long T,n,x,y,z; 
long long solve(int n,int x,int y,int z){
	long long ans = 0;
	for(long long i=1;i<=n;i++){
		for(long long j=0;j<=n-i;j++){
			long long m =n-i-j;
			long long H = m*j*x + (m*y) + j*(j-1)/2*x;
			long long cur = H *i + (1+i)*i/2 * j*x + i*z;
//			cout<<i<<" "<<j<<" "<<m<<" "<<cur<<endl;
			ans = max(ans,cur);
		}
	}
	return ans;
}
int main(){
    scanf("%lld",&T);
    while(T--){
    	scanf("%lld %lld %lld %lld",&n,&x,&y,&z);
    	long long ans = solve(n,x,y,z);
    	printf("%lld\n",ans);
	}
}