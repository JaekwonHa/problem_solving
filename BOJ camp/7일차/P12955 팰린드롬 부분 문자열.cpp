#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
int pattern[20];

bool check(int start, int n) {
	int l = start, r = start + M - 1;
	while (l < r) {
		if (pattern[l++] != pattern[r--]) return false;
	}
	return true;
}

long long checkPattern(int n, int k) {
	int cnt = 0;
	for (int i = 0; i < n - M + 1; i++) {
		if (check(i,n)) cnt++;
	}
	if (cnt < K) return 0;

	long long ret = 1;
	for (int i = 0; i < k; i++) {
		ret *= (26 - i);
	}
	return ret;
}

long long f(int n, int k) {
	if (n == N) {
		// 패턴의 경우의 수 계산
		return checkPattern(n, k);
	}

	long long ret = 0;
	for (int i = 1; i <= k && i <= 26; i++) {
		pattern[n] = i;
		ret += f(n + 1, k);
		pattern[n] = 0;
	}
	pattern[n] = k+1;
	ret += f(n + 1, k+1);
	pattern[n] = 0;
	return ret;
}

int main() {

	scanf("%d %d %d", &N, &M, &K);

	printf("%lld\n", f(0, 0));

	return 0;
}

