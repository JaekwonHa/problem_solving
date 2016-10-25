#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 987654321

int N,arr[1010];
int DP[1010];


int f(int n) {
	if(DP[n]!=-1) return DP[n];

	int maxii=0;
	int maxi = max(arr[n], arr[n-1]);
	int mini = min(arr[n], arr[n-1]);
	for(int i=2; i<=n; i++) {
		maxi = max(maxi, arr[n-i+1]);
		mini = min(mini, arr[n-i+1]);
		if(i == n-1) continue;
		maxii = max(maxii, f(n-i)+maxi-mini);
	}
	return DP[n] = maxii;
}

int main() {

	scanf("%d", &N);
	for(int i=1; i<=N; i++) scanf("%d", &arr[i]);

	memset(DP,-1,sizeof(DP));

	DP[1] = 0;
	DP[2] = arr[1]>=arr[2]?arr[1]-arr[2]:arr[2]-arr[1];
	printf("%d\n", f(N));

	return 0;
}