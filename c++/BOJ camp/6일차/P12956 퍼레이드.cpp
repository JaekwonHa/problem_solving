#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321

int N, M;
int map[101][101];
int mapFloyd[101][101];

int solve(int dfrom, int dto) {

	int tempMap[101][101];
	memcpy(tempMap, map, sizeof(map));

	tempMap[dfrom][dto] = INF;
	tempMap[dto][dfrom] = INF;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (tempMap[i][j] > tempMap[i][k] + tempMap[k][j]) {
					tempMap[i][j] = tempMap[i][k] + tempMap[k][j];
					tempMap[j][i] = tempMap[i][k] + tempMap[k][j];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (mapFloyd[i][j] < tempMap[i][j]) ans++;
		}
	}
	return ans;
}

int main() {

	scanf("%d %d", &N, &M);

	memset(map, 1, sizeof(map));
	memset(mapFloyd, 1, sizeof(mapFloyd));

	vector<tuple<int, int, int>> edges(M);
	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a][b] = c;
		map[b][a] = c;
		mapFloyd[a][b] = c;
		mapFloyd[b][a] = c;
		edges[i] = tie(a, b, c);
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (mapFloyd[i][j] > mapFloyd[i][k] + mapFloyd[k][j]) {
					mapFloyd[i][j] = mapFloyd[i][k] + mapFloyd[k][j];
					mapFloyd[j][i] = mapFloyd[i][k] + mapFloyd[k][j];
				}
			}
		}
	}

	int *ans = new int[M];
	for (int i = 0; i < M; i++) {
		if (i != 0) printf(" ");
		tie(a, b, c) = edges[i];
		ans[i] = solve(a, b);
		printf("%d", ans[i]);
	}
	printf("\n");

	return 0;
}

