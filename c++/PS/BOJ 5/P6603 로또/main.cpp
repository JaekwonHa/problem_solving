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
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

vector<int> v;
vector<int> ans;

int K;

void dfs(int pos, int len) {
	if (len == 6) {
		for (auto a : ans) {
			printf("%d ", a);
		}
		printf("\n");
		return;
	}
	for (int i = pos; i < K - 6 + 1 + len; i++) {
		ans.push_back(v[i]);
		dfs(i + 1, len + 1);
		ans.pop_back();
	}
}

int main() {
	bool first = true;
	while (1) {

		if (!first) printf("\n");
		if (first) first = false;
		scanf("%d", &K);
		if (K == 0) break;
		v.clear();
		for (int i = 0; i < K; i++) {
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}

		for (int i = 0; i < K - 6 + 1; i++) {
			ans.push_back(v[i]);
			dfs(i + 1, 1);
			ans.pop_back();
		}

	}

	return 0;
}