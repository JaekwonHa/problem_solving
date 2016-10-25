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

int visit[500000];
int ans;
int maxD;

void dfs(int n, int p, int d) {
	visit[n] = d;
	int next = 0;
	while (n) {
		next += pow((n % 10), p);
		n /= 10;
	}
	if (visit[next] != 0) {
		ans = visit[next];
		return;
	}
	dfs(next, p, d + 1);
}

int main() {

	int A, P;
	scanf("%d %d", &A, &P);

	dfs(A, P, 1);

	printf("%d\n", ans-1);

	return 0;
}