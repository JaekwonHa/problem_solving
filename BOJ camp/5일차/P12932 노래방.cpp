P12932 노래방#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N, DP[2001][2001];
int arr[2001];

int f(int a, int b) {
	int n = max(a, b)+1;
	if (n == N+1) return 0;

	int &ret = DP[a][b];
	if (ret != -1) return ret;

	int t;
	if (a == 0) t = 0;
	else t = abs(arr[n] - arr[a]);
	ret = f(n, b) + t;

	if (b == 0) t = 0;
	else t = abs(arr[n] - arr[b]);
	ret = min(ret,f(a, n) + t);

	return ret;
}

int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", arr + i);

	memset(DP, -1, sizeof(DP));
	printf("%d\n", f(0, 0));

	return 0;
}

