#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int N, K, arr[2002];
map<int, int> DP[2002][4];

int gcd(int a, int b) {
	int r = a%b;
	if (r == 0) return b;
	return gcd(b, r);
}

int f(int n, int t, int k) {

	if (t == 0) {
		if (k == 1) {
			return 1;
		}
		return 0;
	}
	if (n == 0) {
		return 0;
	}
	if (DP[n][t].count(k) > 0) return DP[n][t][k];

	int &ret = DP[n][t][k];
	ret = 0;
	ret += f(n - 1, t, k);
	ret += f(n - 1, t - 1, k / (gcd(arr[n], k)));

	return ret;
}

int main() {

	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);

	printf("%d\n", f(N, 3, K));

	return 0;
}

