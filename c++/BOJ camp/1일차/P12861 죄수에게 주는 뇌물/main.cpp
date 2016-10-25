#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 987654321

int P, Q,A[110];
int DP[10010][10010];

int f(int l, int r) {
	if (l == r) return 0;

	int &ret = DP[l][r];
	if (ret != -1) return ret;

	int ans = INF;
	for (int i = 0; i < Q; i++) {
		int k = A[i];
		if (k <= r && k >= l) {
			ans = min(ans, f(l, k - 1) + f(k + 1, r) + r - l);
		}
	}
	if (ans == INF) {
		ret = 0;
	}
	else {
		ret = ans;
	}
	return ret;
}

int main() {

	scanf("%d %d", &P, &Q);
	for (int i = 0; i < Q; i++)
		scanf("%d", &A[i]);

	memset(DP, -1, sizeof(DP));
	printf("%d\n", f(1, P));

	return 0;
}