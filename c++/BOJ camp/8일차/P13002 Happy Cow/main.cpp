#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321
#define p 10000007
typedef long long ll;

int N, Hi[2010];
int DP[2010][2010];

int f(int i, int j) {
	int &ret = DP[i][j];
	if (ret != -1) return ret;

	int day = i + (N - j);
	if (day > N) return 0;

	ret = 0;
	ret = max(ret, f(i + 1, j) + Hi[i] * day);
	ret = max(ret, f(i, j - 1) + Hi[j] * day);
	return ret;
}

int main() {

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", Hi + i);

	memset(DP, -1, sizeof(DP));
	printf("%d\n", f(1, N));
	return 0;
}

