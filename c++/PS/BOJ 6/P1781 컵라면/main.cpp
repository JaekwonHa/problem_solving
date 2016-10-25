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

struct Problem {
	int deadline, point;
	bool operator < (const Problem a) const {
		if (deadline == a.deadline) return point > a.point;
		return deadline < a.deadline;
	}
};

int n;
Problem arr[200001];

int main() {

	int a, b, c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &b, &c);
		arr[i].deadline = b;
		arr[i].point = c;
	}

	sort(arr, arr + n);

	priority_queue<int, vector<int>, greater<int>> pq;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += arr[i].point;
		pq.push(arr[i].point);
		while (pq.size() > arr[i].deadline) {
			ans -= pq.top();
			pq.pop();
		}
	}

	printf("%d\n", ans);

	return 0;
}