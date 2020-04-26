#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321

char S[2501], T[2501];
int N, A[2501], DP[2501][501][2];

int f(int p, int x, int u) {
	int &ret = DP[p][x][u];
	if (ret != -1) return ret;

	if (p == N) return ret = 0;

	int z = 0;
	ret = INF;
	for (int type = 0; type < 2; type++) {
		for (int y = 0; y <= 500; y++) {
			if (type == 0) {
				if ((A[p] + 9 * y) % 10 != 0) continue;
			}
			else {
				if ((A[p] + y) % 10 != 0) continue;
			}
			if (type == u) {
				z = max(y - x, 0);
				ret = min(ret, z + f(p + 1, y, type));
			}
			else {
				z = y;
				ret = min(ret, z + f(p + 1, y, type));
			}
		}
	}
	return ret;
}

int main() {

	scanf("%s %s", S, T);
	N = strlen(S);
	for (int i = 0; i < N; i++) {
		A[i] = (S[i] + 10 - T[i]) % 10;
	}
	memset(DP, -1, sizeof(DP));
	printf("%d\n", f(0, 0, 0));

	return 0;
}

