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

vector<int> v[100001];
int parent[100001];

int main() {

	int n;
	scanf("%d", &n);
	int from, to;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
		v[to].push_back(from);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (auto a : v[now]) {
			if (parent[a] != 0) continue;
			parent[a] = now;
			q.push(a);
		}
	}

	for (int i = 2; i <= n; i++)
		printf("%d\n", parent[i]);

	return 0;
}