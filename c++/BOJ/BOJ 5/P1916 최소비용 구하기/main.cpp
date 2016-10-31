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
#include <deque>
#include <functional>
using namespace std;

#define INF 987654321
#define mod 1000000007
#define mp make_pair
typedef long long ll;

int N, M;
vector<pair<int,int>> v[1001];

int DS(int start, int dest) {
	int d[1001];
	for (int i = 0; i <= N; i++) d[i] = INF;

	priority_queue<pair<int, int>> pq;
	d[start] = 0;
	pq.push(mp(0, start));

	while (!pq.empty()) {
		int now, cost;
		tie(cost, now) = pq.top();
		pq.pop();

		cost = -cost;
		if (d[now] < cost) continue;

		for (auto a : v[now]) {
			int next = a.second;
			int nextC = a.first + d[now];

			if (d[next] > nextC) {
				d[next] = nextC;
				pq.push(mp(-nextC, next));
			}
		}
	}
	return d[dest];
}

int main() {

	scanf("%d %d", &N, &M);
	int from, to, cost, start, dest;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(mp(cost,to));
	}
	scanf("%d %d", &start, &dest);

	printf("%d\n", DS(start, dest));

	return 0;
}