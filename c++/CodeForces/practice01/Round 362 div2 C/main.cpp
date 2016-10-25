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


int main() {

	int q;
	ll a, b, c, d;
	
	map<ll, ll> m;
	scanf("%d", &q);
	while (q--) {
		scanf("%I64d %I64d %I64d", &a, &b, &c);
		if (a == 1) {
			scanf("%I64d", &d);
			ll u = b, v = c;
			//LCA
			while (v != u) {
				if (v < u) swap(v, u);
				m[v] += d;
				v /= 2;
			}
		}
		else {
			ll ans = 0;
			ll u = b, v = c;
			while (v != u) {
				if (v < u) swap(v, u);
				if (m.find(v) != m.end()) ans += m[v];
				v /= 2;
			}
			printf("%I64d\n", ans);
		}
	} 

	return 0;
}