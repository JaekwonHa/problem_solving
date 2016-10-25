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
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

int N, M, K;
char m[101][101];
char ans[81];
int visit[101][101][81];

int len;
int ANSWER;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

typedef struct Point {
	int x, y, cnt;
	Point(int a, int b, int c) : x(a), y(b), cnt(c) {}
	Point() {
		x = 0, y = 0, cnt = 0;
	}
};

int dfs(Point now) {
	int &ret = visit[now.x][now.y][now.cnt];
	if (ret != -1) return ret;

	ret = 0;
	if (now.cnt == len - 1) { return ret=1; }
	for (int k = 1; k <= K; k++) {
		for (int i = 0; i < 4; i++) {
			int nextX, nextY;
			nextX = now.x + dx[i] * k;
			nextY = now.y + dy[i] * k;
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
			if (m[nextX][nextY] == ans[now.cnt + 1]) {
				ret += dfs(Point(nextX, nextY, now.cnt + 1));
			}
		}
	}
	return ret;
}

int main() {

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) scanf("%s", m[i]);
	scanf("%s", ans);

	queue<Point> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (m[i][j] == ans[0]) q.push(Point(i, j, 0));
		}
	}
	len = strlen(ans);
	memset(visit, -1, sizeof(visit));

	while (!q.empty()) {
		ANSWER += dfs(q.front());
		q.pop();
	}

	printf("%d\n", ANSWER);

	return 0;
}