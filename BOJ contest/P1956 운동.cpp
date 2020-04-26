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

int n,m, v[401][401];

int main() {

	scanf("%d %d", &n, &m);

	int from, to, cost;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			v[i][j] = INF;
		}
	}	
	
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		v[from][to] = cost;
	}
	

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	int ans = INF;
	for (int i = 1; i <= n; i++) {
		ans = min(ans, v[i][i]);
	}

	if (ans == INF) ans = -1;
	printf("%d\n", ans);

	return 0;
}