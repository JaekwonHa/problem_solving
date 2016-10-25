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
#include <bitset>
using namespace std;

#define INF 987654321

typedef long long ll;
ll mod = 1LL << 32;

int P[6000003], n, top;
bitset<100000001> prime;

ll modpowers(ll a, int n) {	// a^n
	ll ret = 1;
	while (n) {
		if (n & 1) ret = (ret*a) % mod;
		n >>= 1;
		a = (a*a) % mod;
	}
	return ret;
}

int main() {
	int k;
	scanf("%d", &n);
	P[top++] = 2;
	for (ll i = 3; i <= n; i+=2) {
		if (!prime[i]) {
			P[top++] = i;
			if (i*i > n) continue;
			k = i + i;
			for (int j = i*i; j <= n; j += k) {
				prime[j] = true;
			}
		}
	}
	ll ans = 1;
	for (int i = 0; i < top; i++) {
		ll a = P[i];
		int cnt = 0;
		while (a <= n) {
			a *= P[i];
			cnt++;
		}
		a /= P[i];
		ans = (ans*a) % mod;
	}
	printf("%lld\n", ans);

	return 0;
}