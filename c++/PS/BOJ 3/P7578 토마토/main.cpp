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
#define mod 1000000007
typedef long long ll;

queue<tuple<int, int, int>> q;
int m[1001][1001];
int visit[1001][1001];
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
int h, w;

int main() {

	scanf("%d %d", &w, &h);
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int a;
			scanf("%d", &a);
			if (a == 1) q.push(make_tuple(i, j, 0)), visit[i][j] = 0;
			if (a == -1) m[i][j] = -1;
		}
	}
	while (!q.empty()) {
		int nowX, nowY, cost;
		tie(nowX, nowY, cost) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			int nextC = cost + 1;
			if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) continue;
			if (visit[nextX][nextY] != -1 || m[nextX][nextY] == -1) continue;
			visit[nextX][nextY] = nextC;
			q.push(make_tuple(nextX, nextY, nextC));
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			ans = max(ans, visit[i][j]);
			if (m[i][j] != -1 && visit[i][j] == -1) ans = INF;
		}
	}
	if (ans == INF) ans = -1;
	printf("%d\n", ans);

	return 0;
}