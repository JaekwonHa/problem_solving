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

ll n;
char str[1000010];
int k;
ll cnt[1000010];
// idx, ai, ci
tuple<int, ll, char> query[50001];
// idx, cnt
vector<pair<int,ll>> ans;

int main() {

	scanf("%lld %s %d", &n, str, &k);

	int len = strlen(str);
	for (int i = 0; i < k; i++) {
		ll a;
		char b;
		scanf("%lld %c", &a, &b);
		query[i] = mt(i, a, b);
	}

	sort(query, query + k, [](tuple<int, ll, char> a, tuple<int, ll, char> b) {
		return get<2>(a) < get<2>(b);
	});

	for (int i = 0; i < k; i++) {
		char type = get<2>(query[i]);
		if (i == 0 || type != get<2>(query[i-1])) {
			cnt[0] = str[0] == type;
			for (int j = 1; j < len; j++) {
				cnt[j] = cnt[j - 1] + (str[j] == type);
			}
		}

		ll ai = get<1>(query[i]);
		ll start = 0;
		// 나누기 후 모듈러를 방지하기 위해
		if (ai % 2 == 0) {
			start = (((ai / 2) % len) * ((ai - 1) % len)) % len;
		}
		else {
			start = ((ai % len) * (((ai - 1) / 2) % len)) % len;
		}
		ai--;
		ans.push_back(mp(get<0>(query[i]), (ai + start) / len*cnt[len-1] + cnt[(ai + start) % len] - (start==0?0:cnt[start-1])));
	}

	sort(ans.begin(), ans.end(), [](pair<int, ll> a, pair<int, ll> b) {
		return a.first < b.first;
	});

	for (auto a : ans) {
		printf("%lld\n", a.second);
	}

	return 0;
}