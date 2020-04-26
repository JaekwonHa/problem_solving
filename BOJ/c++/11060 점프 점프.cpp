#include <iostream>
#include <algorithm>
using namespace std;

int N,arr[1111],DP[1111];

int f(int n, int cost) {
	if(n>N) return 987654321;
	if(n==N) return DP[n]=min(cost,DP[n]);
	if(arr[n]==0) return 987654321;

	int ret = DP[n];
	if(ret==987654321) {
		ret=f(n+arr[n], cost+1);
		for(int i=arr[n]-1; i>0; i--) {
			ret = min(ret, f(n+i, cost+1));
		}
		DP[n]=ret;
	}
	return ret;
}
int f2(int n) {
	DP[0]=0;
	for(int i=0; i<n; i++) {
		for(int j=1; j<=arr[i]; j++) {
			DP[i+j] = min(DP[i+j], DP[i]+1);
		}
	}
	return 0;
}

int main() {
	
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &arr[i]);

	for(int i=0; i<=N; i++) DP[i]=987654321;
	//f(0,0);
	f2(N);

	if(DP[N-1]==987654321) printf("%d\n", -1);
	else printf("%d\n", DP[N-1]);

	return 0;
}