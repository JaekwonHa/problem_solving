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
typedef long long ll;

const ll mod = 1e4 + 7;
ll A[4][4];
ll B[4][4] = {
	{ 2, 1, 1, 0 },
	{ 1, 2, 0, 1 },
	{ 1, 0, 2, 1 },
	{ 0, 1, 1, 2 }
};
int n;

void init() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			A[i][j] = B[i][j];
		}
	}
}

void mul(ll a[4][4], ll b[4][4]) {
	ll c[4][4];
	memset(c, 0, sizeof(c));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				c[i][j] += a[i][k] * b[k][j];
				c[i][j] %= mod;
			}
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			a[i][j] = c[i][j];
		}
	}
}

int main() {
	scanf("%d", &n);
	ll S[4][4];
	memset(S, 0, sizeof(S));
	for (int i = 0; i < 4; ++i) {
		S[i][i] = 1;
	}
	init();
	while (n) {
		if (n & 1) {
			mul(S, A);
		}
		mul(A, A);
		n >>= 1;
	}
	printf("%lld\n", S[0][0]);


	return 0;
}

