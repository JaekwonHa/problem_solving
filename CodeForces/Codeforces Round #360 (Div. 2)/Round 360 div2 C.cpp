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

// ������ ll �̻��� ��� INF�� 98765432100000 �������� ũ�� �ؾ���
// �Է¹޴� ���� 10^9 �̰� ���� ���� �װ͵��� ���ϴ� �����̶�� ���� ll �ϼ� �ִ�

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

// split�� �Ҽ� ���� � �׷��� �����̰� �ϳ��� �ִٸ� -1�� ���
// color���� ������ vector�� ��Ɗx�ٰ� ���

int n, m, u, v;
vector<int> edges[100001];
int c[100001];
vector<int> ans[3];

int dfs(int pos, int color) {
	if (c[pos] != 0 && c[pos] != color) return 0;
	if (c[pos] != 0) return 1;

	c[pos] = color;
	ans[color].push_back(pos);

	for (int i : edges[pos]) {
		if (!dfs(i, 3 - color)) {
			return 0;
		}
	}
	return 1;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (edges[i].size() == 0) continue;
		if (c[i] != 0) continue;

		if (!dfs(i, 1)) {
			printf("-1\n");
			return 0;
		}
	}
	
	for (int i = 1; i <= 2; i++) {
		printf("%d\n", ans[i].size());
		for (int j : ans[i]) {
			printf("%d ", j);
		}
		printf("\n");
	}


	return 0;
}