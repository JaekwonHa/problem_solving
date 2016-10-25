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
#include <bitset>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

bool visit['Z'];
int R, C;
char m[21][21];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int ans;

inline void dfs(int x, int y, int depth) {
	if (ans < depth) ans = depth;

	for (int i = 0; i < 4; i++) {
		int nextX, nextY;
		nextX = x + dx[i];
		nextY = y + dy[i];
		if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
		if (visit[m[nextX][nextY]] == true) continue;
		visit[m[nextX][nextY]] = true;
		dfs(nextX, nextY, depth+1);
		visit[m[nextX][nextY]]= false;
	}
}

int main() {

	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) scanf("%s", m[i]);

	visit[m[0][0]] = true;
	dfs(0, 0, 1);

	printf("%d\n", ans);

	return 0;
}