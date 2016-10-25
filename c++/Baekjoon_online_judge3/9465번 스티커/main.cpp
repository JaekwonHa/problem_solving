#include <iostream>
#include <algorithm>
using namespace std;

int T,N,arr[2][100100],DP[100100][3];

int f(int n) {
	DP[0][0]=DP[0][1]=DP[0][2]=DP[1][0]=0;
	DP[1][1]=arr[0][1];
	DP[1][2]=arr[1][1];
	for(int i=2; i<=n; i++) {
		// 제거 안함
		DP[i][0] = max(DP[i-1][1],DP[i-1][2]);

		int a,b,c;
		// 위 제거
		a = DP[i-2][1];
		b = DP[i-1][2];
		c = DP[i-1][0];
		DP[i][1] = max(a,b);
		DP[i][1] = max(DP[i][1],c) + arr[0][i];

		// 아래 제거
		a = DP[i-2][2];
		b = DP[i-1][1];
		c = DP[i-1][0];
		DP[i][2] = max(a,b);
		DP[i][2] = max(DP[i][2],c) + arr[1][i];
	}
	int ans = max(DP[n][0], DP[n][1]);
	ans = max(ans, DP[n][2]);
	return ans;
}

int main() {

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i=0; i<2; i++) {
			for(int j=1; j<=N; j++) {
				scanf("%d", &arr[i][j]);
			}
		}

		printf("%d\n", f(N));
	}

	return 0;
}