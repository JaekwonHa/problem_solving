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

	ll n, cn;
	scanf("%lld", &n);
	cn = n;
	vector<ll> v;

	for (ll i = 2; i*i <= n; i++) {
		if (n%i) continue;
		else {
			while (n%i == 0) n /= i;
			v.push_back(i);
		}
	}
	if (n != 1) v.push_back(n);

	n = cn;

	queue<ll> q;
	queue<int> p;
	queue<bool> c;

	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
		p.push(i);
		c.push(true);
	}
	ll ans = n;
	while (!q.empty()) {
		ll m = q.front(); q.pop();
		int s = p.front(); p.pop();
		bool flg = c.front(); c.pop();

		if (flg) ans -= n / m;
		else ans += n / m;

		for (int i = s + 1; i < v.size(); i++) {
			ll nm = m*v[i];
			if (nm <= n) {
				q.push(nm);
				p.push(i);
				c.push(!flg);
			}
			else break;
		}
	}
	printf("%lld\n", ans);




	return 0;
}