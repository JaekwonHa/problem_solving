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
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

int n, m;
int v[32001];
vector<int> d[32001];

void TS() {
	int x=-1;
	
	int T = n;

	while (T--) {
		if (x == -1) {
			for (int i = 1; i <= n; i++) {
				if (v[i] == 0) {
					x = i;
					break;
				}
			}
		}

		printf("%d ", x);
		v[x] = -1;
		int aa = x;
		x = -1;
		for (auto a : d[aa]) {
			v[a]--;
			if (v[a] == 0) x = a;
		}
	}
}

int main() {

	scanf("%d %d", &n, &m);
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		d[a].push_back(b);
		v[b]++;
	}

	TS();

	return 0;
}