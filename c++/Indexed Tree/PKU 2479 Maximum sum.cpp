#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 50100

int a[MAXN], b[MAXN],arr[MAXN],T,N;
int dp1[MAXN],dp2[MAXN];

void solve() {
	for(int i=1; i<=N; i++) {
		a[i]=max(a[i-1],0)+arr[i];
	}
	for(int i=N; i>0; i--) {
		b[i]=max(b[i+1],0)+arr[i];
	}
	for(int i=1; i<=N; i++)
		dp1[i]=max(dp1[i-1],a[i]);
	for(int i=N; i>=0; i--)
		dp2[i]=max(dp2[i+1],b[i]);
}

int main() {

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		fill(a,a+N+2,-99999);
		fill(b,b+N+2,-99999);
		fill(dp1,dp1+N+2,-99999);
		fill(dp2,dp2+N+2,-99999);
		for(int i=1; i<=N; i++)
			scanf("%d", &arr[i]);

		solve();

		int ans=-99999;
		for(int i=1; i<N; i++) {
			ans = max(ans, dp1[i]+dp2[i+1]);
		}

		printf("%d\n", ans);
	}
	return 0;
}