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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

struct Circle {
	int left, right, radius, x;
};

int n;
Circle arr[300001];

int main() {

	int xi, ri;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &xi, &ri);
		arr[i].radius = ri;
		arr[i].left = xi - ri;
		arr[i].right = xi + ri;
		arr[i].x = xi;
	}

	sort(arr, arr + n, [](Circle a, Circle b) {
		if (a.left == b.left) return a.radius > b.radius;
		return a.left < b.left;
	});

	int ans = 0;
	int sumR = 0;
	for (int i = n - 1; i > 0; i--) {
		if (arr[i - 1].right <= arr[i].left) {
			if (arr[i - 1].right == arr[i].left) {
				sumR += arr[i].radius * 2;
			}
			else {
				sumR = 0;
			}
		}
		else {
			if (arr[i - 1].left == arr[i].left) {
				if (sumR+arr[i].radius*2 == arr[i - 1].radius * 2) {
					ans++;
				}
				sumR = 0;
			}
		}
		ans++;
	}

	printf("%d\n", ans+2);

	return 0;
}