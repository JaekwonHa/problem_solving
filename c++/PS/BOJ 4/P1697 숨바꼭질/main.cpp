#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

int N, K;
int DP[200001];

int f(int pos) {
	if (pos > 2 * K || pos < 0) return INF;
	if (pos == K) return 0;

	int &ret = DP[pos];
	if (ret != -1) return ret;

	ret = INF;
	ret = min(ret, f(pos * 2) + 1);
	ret = min(ret, f(pos + 1) + 1);
	ret = min(ret, f(pos - 1) + 1);

	return ret;
}

int main() {

	scanf("%d %d", &N, &K);

	memset(DP, -1, sizeof(DP));

	if (K < N) {
		printf("%d\n", N - K);
	}
	else {
		printf("%d\n", f(N));
	}
	return 0;
}