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

int DP[100];
int coin[3] = { 1,10,25 };

int main() {

	DP[0] = 0;
	for (int i = 1; i <= 99; i++) {
		DP[i] = INF;
		for (int j = 0; j < 3; j++) {
			if (i - coin[j] >= 0) {
				DP[i] = min(DP[i], DP[i - coin[j]] + 1);
			}
		}
	}

	int T;
	ll n;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		ll ans=0, t;
		while (n) {
			t = n % 100;
			ans += DP[t];
			n /= 100;
		}
		printf("%lld\n", ans);
	}

	return 0;
}