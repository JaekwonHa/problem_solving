#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;

int N, ai[100001], pi[100001], ci[100001];
vector<pair<int,int>> v[100001];

pair<int,int> dfs(int n, int parent, int cost) {
	int subCount = 1;
	int returnCount = 0;

	for (int i = 0; i < v[n].size(); i++) {
		if (v[n][i].first == parent) continue;
		int a, b;
		tie(a, b) = dfs(v[n][i].first, n, cost + v[n][i].second);
		subCount += a;
		returnCount += b;
	}
	if (ai[n] >= cost) {
		return make_pair(subCount, returnCount);
	}
	else {
		return make_pair(subCount, subCount);
	}
}

int main() {

	scanf("%d", &N);
	int a, b;
	for (int i = 1; i <= N; i++) { scanf("%d", &ai[i]); }
	for (int i = 1; i <= N - 1; i++) {
		scanf("%d %d", &a, &b);
		v[i + 1].push_back(make_pair(a, b));
		v[a].push_back(make_pair(i + 1, b));
	}

	printf("%d\n", dfs(1, 1, 0).second);


	return 0;
}

