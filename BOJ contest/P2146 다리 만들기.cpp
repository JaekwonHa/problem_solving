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

int m[101][101], visit[101][101];
int n;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
vector<pair<int, int>> candi;

void bfs(int x, int y, int color) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = color;
	while (!q.empty()) {
		int nowX, nowY;
		tie(nowX, nowY) = q.front();
		q.pop();
		if (m[nowX + 1][nowY] == 0 || m[nowX-1][nowY] == 0 || m[nowX][nowY+1] == 0 || m[nowX][nowY-1] == 0) {
			candi.push_back(make_pair(nowX, nowY));
		}
		for (int i = 0; i < 4; i++) {
			int nextX, nextY;
			nextX = nowX + dx[i];
			nextY = nowY + dy[i];
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
			if (visit[nextX][nextY] != 0 || m[nextX][nextY] == 0) continue;
			q.push(make_pair(nextX, nextY));
			visit[nextX][nextY] = color;
		}
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &m[i][j]);
		}
	}
	int color = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == 0 && m[i][j] == 1) {
				bfs(i, j, color++);
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < candi.size(); i++) {
		for (int j = 0; j < candi.size(); j++) {
			int x1, y1, x2, y2;
			tie(x1, y1) = candi[i];
			tie(x2, y2) = candi[j];
			if (visit[x1][y1] == visit[x2][y2]) continue;
			ans = min(ans, abs(x1 - x2) + abs(y1 - y2));
		}
	}
	printf("%d\n", ans-1);

	return 0;
}