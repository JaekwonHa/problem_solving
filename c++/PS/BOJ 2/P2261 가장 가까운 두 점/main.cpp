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
typedef long long ll;

struct Point {
	int x, y;
	Point() {
	}
	Point(int x, int y) : x(x), y(y) {
	}
	bool operator < (const Point &v) const {
		if (y == v.y) return x < v.x;
		return y < v.y;
	}
};
int dist(Point a, Point b) {
	return pow(abs(a.x - b.x), 2.0) + pow(abs(a.y - b.y), 2.0);
}


int main() {

	int n, x, y;
	scanf("%d", &n);

	vector<Point> a(n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].x, &a[i].y);
	}
	sort(a.begin(), a.end(), [](Point a, Point b) {
		return a.x < b.x;
	});
	set<Point> candidate = { a[0], a[1] };
	int ans = dist(a[0], a[1]);
	int start = 0;

	for (int i = 2; i < n; i++) {
		Point now = a[i];
		while (start < i) {
			auto p = a[start];
			int x = now.x - p.x;
			if (x*x > ans) {
				candidate.erase(p);
				start += 1;
			}
			else break;
		}
		int d = (int)sqrt((double)ans) + 1;
		auto lower_point = Point(-10000, now.y - d);
		auto upper_point = Point(10000, now.y + d);
		auto lower = candidate.lower_bound(lower_point);
		auto upper = candidate.upper_bound(upper_point);
		for (auto it = lower; it != upper; it++) {
			int d = dist(now, *it);
			if (d < ans) ans = d;
		}
		candidate.insert(now);
	}

	printf("%d\n", ans);
	return 0;
}