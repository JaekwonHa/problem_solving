#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321
#define p 1000000007

int N;
long long DP[51][51][51][51];

int f(int pos, int a, int b, int c) {
	if (a < 0 || b < 0 || c < 0) return 0;

	long long &ret = DP[pos][a][b][c];
	if (ret != -1) return ret;

	if (pos == N) {
		if (a == 0 && b == 0 && c == 0) return 1;
		return 0;
	}

	ret = 0;
	ret = (ret + f(pos + 1, a - 1, b, c)) % p;
	ret = (ret + f(pos + 1, a, b - 1, c)) % p;
	ret = (ret + f(pos + 1, a, b, c - 1)) % p;
	ret = (ret + f(pos + 1, a - 1, b - 1, c)) % p;
	ret = (ret + f(pos + 1, a - 1, b, c - 1)) % p;
	ret = (ret + f(pos + 1, a, b - 1, c - 1)) % p;
	ret = (ret + f(pos + 1, a - 1, b - 1, c - 1)) % p;
	return ret;
}

int main() {

	int a, b, c;
	scanf("%d %d %d %d", &N, &a, &b, &c);

	memset(DP, -1, sizeof(DP));
	printf("%d\n", f(0, a, b, c));

	return 0;
}

