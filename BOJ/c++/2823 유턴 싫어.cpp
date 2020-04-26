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
#define p 1000000007
typedef long long ll;

bool visit[15][15][4];
int R, C;
char MAP[15][15];
int ans = 0;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int r, int c, int dir) {
	if (visit[r][c][dir] == true) return;
	visit[r][c][dir] = true;
	bool ok = false;
	int i;
	for (i = 0; i < 4; i++) {
		if (dir == 0 && i == 1) continue;
		if (dir == 1 && i == 0) continue;
		if (dir == 2 && i == 3) continue;
		if (dir == 3 && i == 2) continue;
		if (MAP[r + dx[i]][c + dy[i]] == '.') {
			dfs(r + dx[i], c + dy[i], i);
			ok = true;
		}
	}
	if (ok == false) {
		ans = 1;
		return;
	}
}

int main() {

	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; i++) scanf("%s", MAP[i]+1);

	int startR=-1, startC=-1;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (MAP[i][j] == '.') {
				startR = i;
				startC = j;
				break;
			}
		}
		if (startR != -1) break;
	}
	if (MAP[startR][startC - 1] == '.') dfs(startR, startC, 0);
	if (MAP[startR][startC + 1] == '.') dfs(startR, startC, 1);
	if (MAP[startR - 1][startC] == '.') dfs(startR, startC, 2);
	if (MAP[startR + 1][startC] == '.') dfs(startR, startC, 3);

	printf("%d\n", ans);

	return 0;
}