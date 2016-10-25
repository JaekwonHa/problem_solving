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

vector<int> v[100001];
int ans;
int visit[100001];

int dfs(int n, int start, int d) {
	for (auto a : v[n]) {
		if (a == start) {
			ans -= d;
			return 1;
		}
		if (visit[a] != 0) continue;
		visit[a] = d;
		if (dfs(a, start, d + 1) == 1) {
			return 1;
		}
		visit[a] = 0;
	}
	return 0;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) v[i].clear();
		for (int i = 1; i <= n; i++) {
			int to;
			scanf("%d", &to);
			v[i].push_back(to);
		}
		ans = n;
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				//if (dfs(i, i, 1) == 0) visit[i] = 0;
				dfs(i, i, 1);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}