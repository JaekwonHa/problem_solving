#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int M;
char map[2][55];
bool visit[2][55];

bool dfs(int x, int y) {
	if (map[x][y] == '#') return false;
	if (x < 0 || x>1 || y < 0) return false;
	if (y == M - 1) {
		visit[x][y] = true;
		return true;
	}
	visit[x][y] = true;

	int nextX, nextY;

	// 오른쪽
	nextX = x, nextY = y + 1;
	if (map[nextX][nextY] == '.' && visit[nextX][nextY] == false) {
		if (dfs(nextX, nextY)) return true;
		visit[nextX][nextY] = false;
	}
	// 위
	nextX = x - 1, nextY = y;
	if (nextX == 0) {
		if (map[nextX][nextY] == '.' && visit[nextX][nextY] == false) {
			if (dfs(nextX, nextY)) return true;
			visit[nextX][nextY] = false;
		}
	}

	// 아래
	nextX = x + 1, nextY = y;
	if (nextX == 1) {
		if (map[nextX][nextY] == '.' && visit[nextX][nextY] == false) {
			if (dfs(nextX, nextY)) return true;
			visit[nextX][nextY] = false;
		}
	}
	return false;
}

int getScore() {
	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '.' && visit[i][j] == false)
				ans++;
		}
	}
	return ans;
}

int main() {

	cin >> M;
	cin >> map[0];
	cin >> map[1];
	
	int ans=0;
	
	if (map[0][0] == '.') {
		memset(visit, false, sizeof(visit));
		dfs(0, 0);
		ans = getScore();
	}
	
	if (map[1][0] == '.') {
		memset(visit, false, sizeof(visit));
		dfs(1, 0);
		ans = max(ans, getScore());
	}

	cout << ans << endl;

	return 0;
}