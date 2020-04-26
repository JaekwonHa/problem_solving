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

ll BIT[100001];
ll a[100001];
int n, m;

void update(int x, int val) {
	for (int i = x; i <= n; i += (i&-i)) {
		BIT[i] += val;
	}
}

ll sum(int x) {
	ll ret = 0;
	for (int i = x; i > 0; i -= (i&-i)) {
		ret += BIT[i];
	}
	return ret;
}

int main() {

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		update(i + 1, a[i]);
	}

	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%lld\n", sum(y) - sum(x-1));
	}

	return 0;
}