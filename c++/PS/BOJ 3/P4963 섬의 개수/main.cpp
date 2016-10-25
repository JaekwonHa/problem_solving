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

int m[55][55];
int visit[55][55];
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
int N;
int h, w;

int bfs(int x, int y) {
	int ret = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;
	while (!q.empty()) {
		int nowX, nowY;
		tie(nowX, nowY) = q.front();
		q.pop();
		ret++;
		for (int i = 0; i < 8; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w) continue;
			if (visit[nextX][nextY] != 0 || m[nextX][nextY] == 0) continue;
			visit[nextX][nextY] = 1;
			q.push(make_pair(nextX, nextY));
		}
	}
	return ret;
}

int main() {

	while (1) {
		
		scanf("%d %d", &w, &h);
		if (h == 0 && w == 0) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int a;
				scanf("%d", &m[i][j]);
			}
		}
		memset(visit, 0, sizeof(visit));
		int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (m[i][j] == 1 && visit[i][j] == 0) {
					ans++;
					bfs(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}