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
char m[3500][7000];

void f(int x1, int y1, int x2, int y2) {
	if (y2 - y1 == 6) {
		m[x1][y1 + 2] = '*';
		m[x1 + 1][y1 + 1] = '*';
		m[x1 + 1][y1 + 3] = '*';
		m[x1 + 2][y1] = '*';
		m[x1 + 2][y1+1] = '*';
		m[x1 + 2][y1+2] = '*';
		m[x1 + 2][y1+3] = '*';
		m[x1 + 2][y1+4] = '*';
		return;
	}
	int dy = (y2 - y1)/4;
	int dx = (x2 - x1)/2;
	f(x1, y1 + dy, x1 + dx, y1 + 3 * dy);
	f(x1 + dx, y1, x2, y1 + 2 * dy);
	f(x1 + dx, y1 + 2 * dy, x2, y2);
}

int main() {

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			m[i][j] = ' ';
		}
	}

	f(0, 0, n, 2 * n);

	for (int i = 0; i < n; i++)
		printf("%s\n", m[i]);

	return 0;
}