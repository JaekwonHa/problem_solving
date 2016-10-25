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
using namespace std;

#define INF 987654321
#define mod 1000000007
#define mp make_pair
typedef long long ll;

int main() {

	int n, a;
	ll ans = 0;
	deque<pair<int,int>> dq;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (dq.empty()) {
			dq.push_back(mp(a, 1));
			continue;
		}
		int cnt = 1;
		while (!dq.empty() && dq.back().first <= a) {
			if (dq.back().first == a) {
				cnt += dq.back().second;
			}
			ans += dq.back().second;
			dq.pop_back();
		}
		if (!dq.empty()) ans++;
		dq.push_back(mp(a, cnt));
	}
	printf("%lld\n", ans);

	return 0;
}