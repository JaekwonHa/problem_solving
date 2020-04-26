#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define mp make_pair

vector<pair<int, int> > v[10001];
int N;
int node, depth, visit[10001];

void dfs(int n, int d) {
	if (depth < d) {
		depth = d;
		node = n;
	}
	visit[n] = 1;
	for (int i = 0; i < v[n].size(); i++) {		
		if (visit[v[n][i].first] == 1) continue;
		dfs(v[n][i].first, d + v[n][i].second);
	}
}

int main() {

	
	
	scanf("%d", &N);
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(mp(b, c));
		v[b].push_back(mp(a, c));
	}

	depth = 0;
	memset(visit, 0, sizeof(visit));
	dfs(1, 0);

	depth = 0;
	memset(visit, 0, sizeof(visit));
	dfs(node, 0);

	printf("%d\n", depth);

	return 0;
}

