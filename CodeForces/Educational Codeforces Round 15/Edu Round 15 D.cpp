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

	ll d, ans=0;
	ll k, a, b, t;
	scanf("%I64d %I64d %I64d %I64d %I64d", &d, &k, &a, &b, &t);

	if (d <= k) {
		ans = d*a;
	}
	else {
		if (t + k*a > k*b) {
			ans = k*a + (d - k)*b;
		}
		else {
			int cnt = d / k - 1;
			ans = a*k*(d / k) + cnt*t + min(t + d%k*a, d%k*b);
		}
	}

	

	printf("%I64d\n", ans);

	return 0;
}