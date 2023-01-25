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

int n;
map<ll, int> m;


int main() {
	ll a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &a);
		m[a]++;
	}
	ll ans1 = 0, ans2 = 0;
	for (auto t : m) {
		ll n = 1;
		int i = 0;
		ll number = t.first;
		int Acnt = t.second;

		while (n <= number) n *= 2, i++;
		n /= 2, i--;

		while (i <= 50) {
			if (n <= 0) break;
			auto B = m.find(n - number);
			
			if (B != m.end() && B->first != number) {
				ans1 += (ll)(Acnt*B->second);
			}
			if (B != m.end() && B->first == number) {
				ans2 += ((ll)Acnt*(Acnt - 1LL)) / 2LL;
			}
			i++, n *= 2;
		}
	}
	printf("%I64d\n", ans1 / 2LL + ans2);

	return 0;
}