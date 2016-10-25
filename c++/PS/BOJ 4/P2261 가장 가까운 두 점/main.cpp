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


struct Point {
	int x, y;
	Point() {
	}
	Point(int a, int b) : x(a), y(b) {
	}
	bool operator < (const Point &a) const {
		if (y == a.y) return x < a.x;
		return y < a.y;
	}
};

int dist(Point a, Point b) {
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}


int n;
Point arr[100001];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].x, &arr[i].y);

	sort(arr, arr + n, [](Point a, Point b) {
		return a.x < b.x;
	});

	set<Point> candi;
	

	candi.insert(arr[0]);
	candi.insert(arr[1]);
	int min = dist(arr[0], arr[1]);

	int start = 0;
	for (int i = 2; i < n; i++) {
		Point now = arr[i];
		while (start < i) {
			int d = now.x - arr[start].x;
			if (d*d > min) {
				candi.erase(arr[start]);
				start++;
			}
			else break;
		}
		int d = sqrt(min);
		auto lower = candi.lower_bound(Point(-10000, now.y - d));
		auto upper = candi.upper_bound(Point(10000, now.y + d));
		for (auto it = lower; it != upper; it++) {
			int d = dist(now, *it);
			if (d < min) {
				min = d;
			}
		}
		candi.insert(now);
	}
	printf("%d\n", min);

	return 0;
}