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


int main() {

	int n,m;
	scanf("%d %d", &n, &m);
	int *arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int from, to, cost;
	double ans;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		ans = max(ans, (arr[from] + arr[to]) / (double)cost);
	}
	printf("%.6lf\n", ans);

	return 0;
}