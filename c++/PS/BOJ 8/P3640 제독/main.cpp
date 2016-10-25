#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int N, M;
int w[2010][2010];
int c[2010][2010];
int from[2010];
int Isin[2010];
int dist[2010];
vector<int> edge[2010];

int v, e, a, b, d;

int source, sink;

int in_node(int x) {
	return 2 * x;
}
int out_node(int x) {
	return in_node(x) + 1;
}

void add_edge(int s, int e, int cap, int cst) {

	edge[s].push_back(e);
	edge[e].push_back(s);
	w[s][e] = cap;
	c[s][e] = cst;
	c[e][s] = -cst;
}

int spfa() {

	for (int i = 0; i <= out_node(sink); i++) dist[i] = INF, from[i] = -1, Isin[i] = 0;
	dist[in_node(source)] = 0; from[in_node(source)] = 0; Isin[in_node(source)] = 1;
	queue<int> myQ; myQ.push(in_node(source));

	while (!myQ.empty()) {
		int now = myQ.front(); myQ.pop();
		Isin[now] = 0;

		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i];
			if (!w[now][next]) continue;
			if (dist[next] > dist[now] + c[now][next]) {
				dist[next] = dist[now] + c[now][next];
				from[next] = now;
				if (!Isin[next]) myQ.push(next), Isin[next] = 1;
			}
		}
	}
	return dist[out_node(sink)]<INF;
}


int main()
{
	
	int i, j, k;
	while (cin >> v) {
		
		scanf("%d", &e);

		source = 1, sink = v;
		
		for (int i = 0; i <= out_node(sink); i++) edge[i].clear();
		for (int i = 0; i <= out_node(sink); i++) {
			for (int j = 0; j <= out_node(sink); j++) {
				w[i][j] = 0;
				c[i][j] = 0;
			}
		}

		for (i = 0; i < e; i++) {
			scanf("%d %d %d", &a, &b, &d);
			
			add_edge(out_node(a), in_node(b), 1, d);
		}
		add_edge(in_node(source), out_node(source), 2, 0);
		for (i = 2; i < v; i++) {
			add_edge(in_node(i), out_node(i), 1, 0);
		}
		add_edge(in_node(sink), out_node(sink), 2, 0);

		int ans = 0, cnt = 0;

		while (spfa()) {
			cnt++;
			ans += dist[out_node(sink)];
			for (int i = out_node(sink); i; i = from[i]) w[from[i]][i]--, w[i][from[i]]++;
		}
		printf("%d\n", ans);
	}

	return 0;
}