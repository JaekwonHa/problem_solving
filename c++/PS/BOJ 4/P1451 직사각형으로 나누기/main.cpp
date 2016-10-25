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

ll n, m, ans;
int arr[101][101];

ll getSum(int x1, int y1, int x2, int y2) {
	int ret = 0;
	for (int i = x1; i < x2; i++) {
		for (int j = y1; j < y2; j++) {
			ret += arr[i][j];
		}
	}
	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	ll t1, t2, t3;
	for (int i = 1; i < m; i++) {
		t1 = getSum(0, 0, n, i);
		for (int j = i + 1; j < m; j++) {
			t2 = getSum(0, i, n, j);
			t3 = getSum(0, j, n, m);
			ans = max(ans, t1*t2*t3);
		}

		for (int j = 1; j < n; j++) {
			t2 = getSum(0, i, j, m);
			t3 = getSum(j, i, n, m);
			ans = max(ans, t1*t2*t3);
		}
	}

	for (int i = m - 1; i >= 0; i--) {
		t1 = getSum(0, i, n, m);
		for (int j = 1; j < n; j++) {
			t2 = getSum(0, 0, j, i);
			t3 = getSum(j, 0, n, i);
			ans = max(ans, t1*t2*t3);
		}
	}

	for (int i = 1; i < n - 1; i++) {
		t1 = getSum(0, 0, i, m);
		for (int j = i+1; j < n; j++) {
			t2 = getSum(i, 0, j, m);
			t3 = getSum(j, 0, n, m);
			ans = max(ans, t1*t2*t3);
		}
		for (int j = 1; j < m; j++) {
			t2 = getSum(i, 0, n, j);
			t3 = getSum(i, j, n, m);
			ans = max(ans, t1*t2*t3);
		}
	}
	for (int i = n - 1; i > 0; i--) {
		t1 = getSum(i, 0, n, m);
		for (int j = 1; j < m; j++) {
			t2 = getSum(0, 0, i, j);
			t3 = getSum(0, j, i, m);
			ans = max(ans, t1*t2*t3);
		}
	}
	printf("%lld\n", ans);

	return 0;
}