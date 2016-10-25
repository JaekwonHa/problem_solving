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
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n, v[21][21];
bool destroy[21][21];

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	int ans = 0;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (v[i][j] > v[i][k] + v[k][j]) {
					printf("-1\n");
					return 0;
				}
				if (i == j || j == k || i == k) continue;
				if (v[i][j] == v[i][k] + v[k][j]) {
					destroy[i][j] = true;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (destroy[i][j] == false) ans += v[i][j];
		}
	}

	printf("%d\n", ans/2);

	return 0;
}