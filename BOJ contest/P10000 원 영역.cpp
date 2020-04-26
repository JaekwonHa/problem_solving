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
#define p 1000000007
typedef long long ll;

int N,
pair<int, int> circle[300010];

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, r;
		scanf("%d %d", &x, &r);
		circle[i] = make_pair(x, r);
	}
	sort(circle, circle + N, [](pair<int, int> a, pair<int, int> b) {
		if (a.first - a.second == b.first - b.second) {
			return a.second < b.second;
		}
		return a.first - a.second < b.first - b.second;
	});

	int x = circle[0].first - circle[0].second;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (circle[i].first - circle[i].second == x) {

		}
	}

	return 0;
}