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

typedef struct Point {
	ll idx, height;
	Point() {}
	Point(ll a, ll b) : idx(a), height(b) {}
};

int main() {

	freopen("input.txt", "r", stdin);

	while (1) {
		ll n,i=0;
		ll ans = 0, a;
		scanf("%lld", &n);
		if (n == 0) break;
		stack<Point> s;

		s.push(Point(0, 0));
		for (i = 1; i <= n; i++) {
			scanf("%lld", &a);
			while (!s.empty() && s.top().height > a) {
				Point now = s.top();
				s.pop();
				ll aa = now.height*(i - s.top().idx - 1);
				ans = max(ans, aa);
			}
			s.push(Point(i, a));
		}
		while (!s.empty()) {
			Point now = s.top();
			s.pop();
			if (!s.empty()) {
				ll aa = now.height*(i - s.top().idx - 1);
				ans = max(ans, aa);
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}