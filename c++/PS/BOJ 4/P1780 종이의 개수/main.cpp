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

int n;
int m[2500][2500];
int ans[3];

void f(int x1, int y1, int x2, int y2) {
	int type = m[x1][y1];
	bool ok = true;
	for (int i = x1; i < x2 && ok; i++) {
		for (int j = y1; j < y2 && ok; j++) {
			if (m[i][j] != type) ok = false;
		}
	}
	if (ok) ans[type + 1]++;
	else {
		int d = (x2 - x1) / 3;
		f(x1, y1, x1 + d, y1 + d);
		f(x1, y1 + d, x1 + d, y1 + 2 * d);
		f(x1, y1 + 2 * d, x1 + d, y1 + 3 * d);
		f(x1 + d, y1, x1 + 2 * d, y1 + d);
		f(x1 + d, y1 + d, x1 + 2 * d, y1 + 2 * d);
		f(x1 + d, y1 + 2 * d, x1 + 2 * d, y1 + 3 * d);
		f(x1 + 2 * d, y1, x2, y1 + d);
		f(x1 + 2 * d, y1 + d, x2, y1 + 2 * d);
		f(x1 + 2 * d, y1 + 2 * d, x2, y1 + 3 * d);
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &m[i][j]);
		}
	}

	f(0, 0, n, n);
	
	for (auto a : ans) {
		printf("%d\n", a);
	}

	return 0;
}