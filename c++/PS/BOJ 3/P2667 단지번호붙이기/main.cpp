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

char m[30][30];
int visit[30][30];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1};
int N;

int bfs(int x, int y, int idx) {
	int ret = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = idx;
	while (!q.empty()) {
		int nowX, nowY;
		tie(nowX, nowY) = q.front();
		q.pop();
		ret++;
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
			if (visit[nextX][nextY] != 0 || m[nextX][nextY]=='0') continue;
			visit[nextX][nextY] = idx;
			q.push(make_pair(nextX, nextY));
		}
	}
	return ret;
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", m[i]);

	vector<int> list;
	int ans = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (m[i][j] == '1' && visit[i][j] == 0) {
				list.push_back(bfs(i, j, ans++));
			}
		}
	}
	sort(list.begin(), list.end());
	printf("%d\n", list.size());
	for (auto a : list) {
		printf("%d\n", a);
	}

	return 0;
}