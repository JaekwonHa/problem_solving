#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define p 1000000007

int map[8][8];
long long DP[8][100001],D;

long long f(int n, int d) {
	if (d == D) {
		if (n == 0) return 1;
		return 0;
	}

	long long &ret = DP[n][d];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i < 8; i++) {
		if (map[n][i] == 0) continue;
		ret = (ret + f(i, d + 1)) % p;
	}
	return ret;
}

int main() {

	scanf("%d", &D);

	map[0][1] = map[0][2] = 1;
	map[1][0] = map[1][2] = map[1][3] = 1;
	map[2][0] = map[2][1] = map[2][3] = map[2][5] = 1;
	map[3][4] = map[3][5] = map[3][1] = map[3][2] = 1;
	map[4][3] = map[4][5] = map[4][6] = 1;
	map[5][2] = map[5][3] = map[5][4] = map[5][7] = 1;
	map[6][4] = map[6][7] = 1;
	map[7][6] = map[7][5] = 1;

	memset(DP, -1, sizeof(DP));
	printf("%lld\n", f(0, 0));

	return 0;
}

