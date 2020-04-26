#include <iostream>
#include <algorithm>
using namespace std;

int T,N,DP[110];

int f(int a) {
	if(DP[a]==0) {
		for(int i=a-1; i>1; i--) {
			if(a%i==0) {
				DP[a]=1+f(a/i);
			}
		}
	}
	return DP[a];
}

int f2(int a) {
	int i,ans=2;
	for(i=2; i*i<a; i++) {
		if(a%i==0) ans+=2;
	}
	if(i*i==a) ans--;
	return ans;
}

int solve(int n) {
	int ans=1;
	DP[1]=1,DP[2]=2,DP[3]=2;
	for(int i=4; i<=n; i++) {
		//if(f(i)%2==1) ans++;
		if(f2(i)%2==1) ans++;
	}
	return ans;
}

int main() {

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		printf("%d\n", solve(N));
	}

	return 0;
}