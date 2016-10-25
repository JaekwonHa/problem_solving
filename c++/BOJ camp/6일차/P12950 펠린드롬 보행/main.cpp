#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N, M, DP[21][21],map[21][21];

int f(int a, int b) {
	if (a == b) return 0;
	if (map[a][b] != 0) return 1;

	int &ret = DP[a][b];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[a][i]!=0 && map[b][j]!=0 && map[a][i] == map[b][j]) {
				ret = min(ret, f(i, j) + 2);
			}
		}
	}
	return ret;
}

int solve() {
	if (map[0][1] != 0) return 1;
	int ans = INF;
	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			if (map[0][i] == map[1][j]) {
				ans = min(ans, f(i, j)+2);
			}
		}
	}

	return ans;
}

int main() {

	int a, b;
	char c;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %c", &a, &b, &c);
		map[a][b] = c;
		map[b][a] = c;
	}

	memset(DP, -1, sizeof(DP));
	int ans = f(0, 1);
	if (ans >= INF) ans = -1;
	printf("%d\n", ans);

	return 0;
}

