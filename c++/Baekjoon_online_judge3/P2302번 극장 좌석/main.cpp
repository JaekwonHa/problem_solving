#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 50

int N,M,arr[MAXN],DP[MAXN],ans;

void solve() {
	DP[0]=1;
	DP[1]=1;
	if(arr[1]==1) DP[2]=1;
	ans=1;
	for(int i=2; i<=N; i++) {
		if(arr[i]==0 && DP[i]>0) continue;
		if(arr[i]==0) {
			DP[i]=DP[i-1]+DP[i-2];
		} else {
			DP[i]=1;
			DP[i+1]=1;
			ans*=DP[i-1];
		}
	}
	ans*=DP[N];
}

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for(int i=0; i<M; i++) {
		int a;
		scanf("%d", &a);
		arr[a]=1;
	}

	solve();

	printf("%d", ans);
		

	return 0;
}