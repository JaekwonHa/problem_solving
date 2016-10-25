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

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n;
int arr[10010];
ll DP[10010][2];

ll f(int pos, int type) {
	ll &ret = DP[pos][type];
	if (ret != -1) return ret;

	if (pos >= n) return 0;

	if (type == 1) {
		ret = arr[pos - 1] * arr[pos] + f(pos + 1, 0);
	}
	else {
		ret = -INF;
		if(pos<n - 1) ret = max(ret, arr[pos] * arr[pos + 1] + f(pos + 2, 0));
		ret = max(ret, arr[pos] + f(pos + 1, 0));
	}

	return ret;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	sort(arr, arr + n);
	arr[n] = 1;

	memset(DP, -1, sizeof(DP));

	ll ans = f(0, 0);

	printf("%ld\n", ans);

	return 0;
}