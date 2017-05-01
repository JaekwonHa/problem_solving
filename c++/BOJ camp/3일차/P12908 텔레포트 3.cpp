#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 9876543210

vector<pair<long long, int> > v[10];
priority_queue<pair<long long, int> > pq;

long long getCost(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

long long DST(int start, int end) {
	long long dis[10];
	for (int i = 0; i<8; i++) dis[i] = INF;

	dis[start] = 0;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		pair<long long, int> value = pq.top();
		pq.pop();

		int current = value.second;
		long long cost = -value.first;

		//현재 정점까지의 거리가 더 짧은 경우 무시
		if (dis[current] < cost) continue;

		for (int i = 0; i<v[current].size(); i++) {
			int next = v[current][i].second;
			long long nextCost = v[current][i].first + dis[current];

			if (dis[next] > nextCost) {
				dis[next] = nextCost;
				pq.push(make_pair(-nextCost, next));
			}
		}
	}
	return dis[end];
}

int main() {
	int x[10], y[10];
	for (int i = 0; i < 8; i++) cin >> x[i] >> y[i];

	long long cost;
	for (int i = 2; i < 8; i += 2) {
		v[i].push_back(make_pair(10, i + 1));
		v[i + 1].push_back(make_pair(10, i));
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == j) continue;
			cost = getCost(x[i], y[i], x[j], y[j]);
			v[i].push_back(make_pair(cost, j));
		}
	}
	cout << DST(0, 1) << endl;
	
	return 0;
}