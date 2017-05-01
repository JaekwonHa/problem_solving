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
typedef long long ll;

#define MAXN 10001

int n;
int sum[MAXN], d[MAXN], w[MAXN];
vector<int> v[MAXN];

int TS() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) q.push(i);
	}
	int ret = 0;
	int T = n;
	while (T--) {
		int x = q.front();
		q.pop();

		sum[x] = max(sum[x], w[x]);
		ret = max(ret, sum[x]);

		for (auto a : v[x]) {
			d[a]--;
			if (d[a] == 0) q.push(a);
			sum[a] = max(sum[a], sum[x] + w[a]);
		}
	}
	return ret;
}


int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		int k,a;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &a);
			v[i].push_back(a);
			d[a]++;
		}
	}

	printf("%d\n", TS());

	return 0;
}