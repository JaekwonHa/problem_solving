#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 40000

struct Robot {
	int n, cost1, cost2;
	/*
	Robot operator < (Robot a) {
		if (cost1*cost2 < a.cost1*a.cost2) {
			return Robot(n, cost1, cost2);
		}
		return a;
	}
	*/
};
priority_queue<tuple<int,int,int>> pq;

int N, map1[21][21], map2[21][21];

int DST(int start, int end) {
	int dis[21];
	for (int i = 0; i < N; i++) {
		dis[i] = INF;
	}

	dis[start] = 0;
	Robot robot;
	robot.n = 0;
	robot.cost1 = 0;
	robot.cost2 = 0;
	pq.push(make_tuple(robot.n, robot.cost1, robot.cost2));

	while (!pq.empty()) {
		int current = get<0>(pq.top());
		int cost1 = get<1>(pq.top());
		int cost2 = get<2>(pq.top());
		pq.pop();

		//현재 정점까지의 거리가 더 짧은 경우 무시
		if (dis[current] < cost1*cost2) continue;

		for (int i = 1; i<N; i++) {
			if (current == i || map1[current][i] == INF) continue;
			int next = i;
			int nextCost1 = cost1 + map1[current][i];
			int nextCost2 = cost2 + map2[current][i];

			if (dis[next] > nextCost1*nextCost2) {
				dis[next] = nextCost1*nextCost2;
				pq.push(make_tuple(next, nextCost1, nextCost2));
			}
		}
	}
	return dis[1];
}

int main() {
	
	scanf("%d", &N);

	char c[21];
	for (int i = 0; i < N; i++) {
		scanf("%s", &c);
		for (int j = 0; j < N; j++) {
			if (c[j] == '.') {
				map1[i][j] = INF;
			}
			else {
				map1[i][j] = c[j] - '0';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		scanf("%s", &c);
		for (int j = 0; j < N; j++) {
			if (c[j] == '.') {
				map2[i][j] = INF;
			}
			else {
				map2[i][j] = c[j] - '0';
			}
		}
	}
	int ans = DST(0, 1);
	if (ans == INF) ans = -1;
	printf("%d\n", ans);

	return 0;
}

