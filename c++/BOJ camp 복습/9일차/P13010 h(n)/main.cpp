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

ll root(ll n, int d) {
	ll r = floor(pow(n, 1.0 / (double)d));
	for (ll i = r - 1; i <= r + 1; i++) {
		ll p = 1;
		for (int j = 0; j < d; j++) {
			p *= i;
		}
		if (p == n) return i;
	}
	return -1;
}

int getCount(ll n) {
	int cnt = 0;
	ll i;
	for (i = 1; i*i <= n; i++) {
		if (n%i == 0) cnt += 2;
	}
	i--;
	if (i*i == n) cnt--;
	return cnt;
}

int main() {

	ll ans = -1, n;
	scanf("%lld", &n);
	bool ok = false;
	for (int i = 2; i <= 59; i++) {
		ll t = root(n, i);
		if (t == -1) continue;
		if (getCount(t) == i) {
			if (ok == false) ans = t, ok = true;
		}
	}

	printf("%lld\n", ans);

	return 0;
}