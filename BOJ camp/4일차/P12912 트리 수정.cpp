#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define mp make_pair
#define mt make_tuple
typedef long long ll;

int N;
vector<pair<int, ll>> v[2001];

pair<int, ll> bfs(int from, int dfrom, int dto) {

	bool visit[2001] = { false, };
	queue <pair<int, ll>> q;
	q.push(mp(from, 0));
	visit[from] = true;
	int n=from;
	ll depth=0;

	while (!q.empty()) {
		int now;
		ll cost;
		tie(now, cost) = q.front();
		q.pop();
		
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			ll nextCost = v[now][i].second + cost;
			if (visit[next] == true) continue;
			if (now == dfrom && next == dto) continue;
			if (now == dto && next == dfrom) continue;
			q.push(mp(next, nextCost));
			visit[next] = true;
			if (depth < nextCost) {
				n = next; depth = nextCost;
			}
		}
	}
	return make_pair(n, depth);
}

ll dist(int from, int dfrom, int dto) {
	auto p1 = bfs(from, dfrom, dto);
	auto p2 = bfs(p1.first, dfrom, dto);
	return p2.second;
}

int main() {

	scanf("%d", &N);
	vector<tuple<int, int, ll>> edges(N-1);
	int from, to, cost;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(mp(to, cost));
		v[to].push_back(mp(from, cost));
		edges[i] = mt(from, to, cost);
	}
	ll ans = 0;
	for (int i = 0; i < edges.size(); i++) {
		tie(from, to, cost) = edges[i];
		ll left = dist(from, from, to);
		ll right = dist(to, from, to);
		if (ans < left + right + cost) {
			ans = left + right + cost;
		}
	}

	printf("%lld", ans);
	return 0;
}

