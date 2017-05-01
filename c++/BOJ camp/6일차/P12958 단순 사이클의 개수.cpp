#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;

#define INF 987654321

int N, K;
int map1[10][10];
int map2[10][10];

/*
bool next_permutation(vector<int> &a, int n) {
	
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	if (i <= 0) return false; // 마지막 순열

	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;

	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}
	return true;
}
*/

int solve(vector<int> &P) {

	int ans = 0;
	for (int ai = 1; ai <= N; ai++) {
		for (int aj = 1; aj <= N; aj++) {
			if (ai == aj) continue;
			if (map1[ai][aj] + map2[P[ai-1]][P[aj - 1]] + 2 == K) {
				ans++;
			}
		}
	}
	return ans;
}

int main() {

	char c[10];
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map1[i][j] = INF;
			map2[i][j] = INF;
		}
	}

	for (int i = 0; i < N; i++) {
		scanf("%s", c);
		for (int j = 0; j < strlen(c); j++) {
			if (c[j] == 'X') map1[i + 1][j + 1] = 1;
			else map1[i + 1][j + 1] = INF;
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", c);
		for (int j = 0; j < strlen(c); j++) {
			if (c[j] == 'X') map2[i + 1][j + 1] = 1;
			else map2[i + 1][j + 1] = INF;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (map1[i][j] > map1[i][k] + map1[k][j]) {
					map1[i][j] = map1[i][k] + map1[k][j];
					map1[j][i] = map1[i][k] + map1[k][j];
				}
				if (map2[i][j] > map2[i][k] + map2[k][j]) {
					map2[i][j] = map2[i][k] + map2[k][j];
					map2[j][i] = map2[i][k] + map2[k][j];
				}
			}
		}
	}

	vector<int> P;
	for (int i = 1; i <= N; i++) P.push_back(i);
	
	int ans = 0;
	do {
		ans = max(ans, solve(P));
	} while (next_permutation(P.begin(), P.end()));
	
	printf("%d\n", ans/2);

	return 0;
}

