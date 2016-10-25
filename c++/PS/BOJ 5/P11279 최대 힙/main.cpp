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
typedef long long ll;

priority_queue<int, vector<int>, less<int>> pq;

int main() {

	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a == 0) {
			int t = 0;
			if (!pq.empty()) t = pq.top(), pq.pop();
			printf("%d\n", t);
		}
		else {
			pq.push(a);
		}
	}

	return 0;
}