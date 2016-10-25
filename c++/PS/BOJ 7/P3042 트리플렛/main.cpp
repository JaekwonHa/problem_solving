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
#include <set>
#include <deque>
#include <functional>
using namespace std;

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n;
char m[101][101];
int dx[4] = { -1,0,1,1 };
int dy[4] = { 1,1,1,0 };

int dfs(int x, int y, int depth, int d) {
	if (m[x][y] == '.') return 0;
	if (x < 0 || x >= n || y < 0 || y >= n) return 0;
	if (depth == 3) return 1;

	int nextX, nextY;
	nextX = x + dx[d];
	nextY = y + dy[d];
	return dfs(nextX, nextY, depth + 1,d);
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", m[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] != '.') {
				ans += dfs(i, j, 1, 0);
				ans += dfs(i, j, 1, 1);
				ans += dfs(i, j, 1, 2);
				ans += dfs(i, j, 1, 3);
			}
		}
	}

	printf("%d\n", 2*ans);

	return 0;
}