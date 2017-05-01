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
char m[7000][7000];

void f(int x1, int y1, int x2, int y2) {
	int d = x2 - x1;
	if (d == 1) {
		m[x1][y1] = '*';
		return;
	}

	d /= 3;
	f(x1, y1, x1 + d, y1 + d);
	f(x1, y1 + d, x1 + d, y1 + 2 * d);
	f(x1, y1 + 2 * d, x1 + d, y2);
	
	f(x1 + d, y1, x1 + 2 * d, y1 + d);
	f(x1 + d, y1 + 2 * d, x1 + 2 * d, y2);

	f(x1 + 2 * d, y1, x2, y1 + d);
	f(x1 + 2 * d, y1 + d, x2, y1 + 2 * d);
	f(x1 + 2 * d, y1 + 2 * d, x2, y2);
}

int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = ' ';
		}
	}

	f(0, 0, n, n);
	for (int i = 0; i < n; i++)
		m[i][n]='\0', printf("%s\n", m[i]);

	return 0;
}