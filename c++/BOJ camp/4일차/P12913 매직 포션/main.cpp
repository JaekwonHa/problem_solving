#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>

#define INF 987654321

struct Robot {
	int n, k,cost;
} robot[55][55];
std::queue<Robot> q;

int N, K;
int map[55][55];

int DST(int start, int end) {
	int dis[55][55];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			dis[i][j] = INF;
		}
	}

	dis[start][K] = 0;
	Robot robot;
	robot.n = 0;
	robot.k = K;
	robot.cost = 0;
	q.push(robot);

	while (!q.empty()) {
		Robot value = q.front();
		q.pop();

		int current = value.n;
		int potion = value.k;
		int cost = value.cost;

		//현재 정점까지의 거리가 더 짧은 경우 무시
		if (dis[current][potion] < cost) continue;

		for (int i = 1; i<N; i++) {
			if (current == i) continue;
			int next = i;
			int nextCost = map[current][next] + dis[current][potion];

			if (dis[next][potion] > nextCost) {
				dis[next][potion] = nextCost;
				Robot t;
				t.n = next;
				t.k = potion;
				t.cost = nextCost;
				q.push(t);
			}
			if (potion > 0 && map[current][next]>0) {
				nextCost = map[current][next]/2 + dis[current][potion];
				if (dis[next][potion-1] > nextCost) {
					dis[next][potion-1] = nextCost;
					Robot t;
					t.n = next;
					t.k = potion-1;
					t.cost = nextCost;
					q.push(t);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= K; i++) {
		ans = std::min(ans, dis[end][i]);
	}
	return ans;
}

int main() {

	scanf("%d %d", &N, &K);
	char input[55];
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		for (int j = 0; j < N; j++) {
			map[i][j] = (input[j] - '0') * 2;
			map[j][i] = (input[j] - '0') * 2;
		}
	}

	double ans = DST(0,1) / 2.0;
	if (ans < 0) ans = 0.0;
	printf("%.1lf\n", ans);
	/*
	double ans = go(0, K, 0) / 2.0;
	if (ans < 0) ans = 0.0;
	printf("%.1lf\n", ans);
	*/
	return 0;
}