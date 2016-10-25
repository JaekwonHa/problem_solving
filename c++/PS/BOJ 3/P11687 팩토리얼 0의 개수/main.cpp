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


int main() {

	ll m;
	while (scanf("%lld", &m) == 1) {
		ll n = 5;
		ll ans = 1;
		ll lb = 1, ub = m * 5;
		ll rere = INF;
		while (lb <= ub) {
			ll md = (lb + ub) / 2;
			n = md * 5;
			ans = 0;
			for (int i = 1; i <= n; i++) {
				ll d = pow(5.0, i);
				if (d > md) break;
				ans += md / d;
			}
			if (ans >= m) ub = md - 1;
			else lb = md + 1;
			if (ans == m) {
				rere = min(rere, md);
			}
		}
		if (rere != INF) printf("%lld\n", rere);
		else printf("-1\n");
	}

	return 0;
}