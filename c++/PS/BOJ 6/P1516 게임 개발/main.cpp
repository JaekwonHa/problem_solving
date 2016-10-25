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
#define MAXN 501
typedef long long ll;

int n, sum[MAXN], w[MAXN], d[MAXN];
vector<int> v[MAXN];

void TS() {
	int ret = 0;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) q.push(i);
	}

	int T = n;
	
	while (T--) {
		int x = q.front();
		q.pop();

		sum[x] = max(sum[x], w[x]);
		ret = max(ret, sum[x]);

		for (auto a : v[x]) {
			d[a]--;
			sum[a] = max(sum[a], sum[x] + w[a]);
			if (d[a] == 0) q.push(a);
		}
	}
}

int main() {
	int a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &w[i], &a);
		while (a != -1) {
			v[a].push_back(i);
			d[i]++;
			scanf("%d", &a);
		}
	}
	TS();
	for (int i = 1; i <= n; i++) {
		printf("%d\n", sum[i]);
	}
	


	return 0;
}