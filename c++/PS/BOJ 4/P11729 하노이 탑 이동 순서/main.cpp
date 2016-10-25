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

queue<pair<int, int>> q;

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		q.push(make_pair(from, to));
		return;
	}
	hanoi(n - 1, from, to, by);
	q.push(make_pair(from, to));
	hanoi(n - 1, by, from, to);
}

int main() {

	int n;
	scanf("%d", &n);

	hanoi(n, 1, 2, 3);
	printf("%d\n", q.size());
	while (!q.empty()) {
		printf("%d %d\n", q.front().first, q.front().second);
		q.pop();
	}

	return 0;
}