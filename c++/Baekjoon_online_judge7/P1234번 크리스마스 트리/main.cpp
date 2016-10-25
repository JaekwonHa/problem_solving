#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

long long DP[12][110][110][110];
long long fac[11];
int R,G,B,N;

void initFac(int n) {
	fac[0]=1;
	for(int i=1; i<=n; i++) {
		fac[i] = fac[i-1]*i;
	}
}

long long f(int n, int r, int g, int b) {
	if(r<0 || g<0 || b<0) return 0;
	if(n==0) return 1;

	long long ans;
	long long& ret = DP[n][r][g][b];
	if(ret != -1) return ret;

	ret =0;

	ret += f(n-1,r-n,g,b);
	ret += f(n-1,r,g-n,b);
	ret += f(n-1,r,g,b-n);
	if(n%2==0) {
		//2,4,8,10
		ret += f(n-1,r-n/2,g-n/2,b)*(fac[n]/fac[n/2]/fac[n/2]);
		ret += f(n-1,r,g-n/2,b-n/2)*(fac[n]/fac[n/2]/fac[n/2]);
		ret += f(n-1,r-n/2,g,b-n/2)*(fac[n]/fac[n/2]/fac[n/2]);
	}
	if(n%3==0) {
		//3,9
		ret += f(n-1,r-n/3,g-n/3,b-n/3)*(fac[n]/fac[n/3]/fac[n/3]/fac[n/3]);
	}
	return ret;
}

int main() {

	cin>>N>>R>>G>>B;
	
	initFac(10);
	memset(DP,-1,sizeof(DP));

	cout<<f(N,R,G,B)<<endl;

	return 0;
}