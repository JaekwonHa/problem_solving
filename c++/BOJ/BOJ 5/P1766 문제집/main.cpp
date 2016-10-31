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


int n, m, a, b;
vector<int> v[32001];
int d[32001];

int main() {

	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		d[b]++;
		v[a].push_back(b);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			pq.push(i);
		}
	}

	int T = n;
	int x;
	while (T--) {
		x = pq.top();
		pq.pop();

		printf("%d ", x);
		d[x] = -1;
		for (auto a : v[x]) {
			d[a]--;
			if (d[a] == 0) pq.push(a);
		}
	}

	return 0;
}