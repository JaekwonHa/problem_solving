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

int n, k, id;
ll arr[100010];
ll cap[100010];
ll sum2[100010];
ll cap_sum[100010];

int main() {

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &arr[i]);
		sum2[i] = sum2[i - 1] + arr[i];
	}

	for (int i = 0; i < k; i++) {
		scanf("%d", &id);
		cap[id] = 1;
	}

	cap[0] = cap[n];
	cap[n + 1] = cap[1];
	arr[0] = arr[n];
	arr[n + 1] = arr[1];

	for (int i = 1; i <= n; i++) {
		cap_sum[i] = cap_sum[i - 1];
		if (cap[i] == 1) cap_sum[i] += arr[i];
	}

	// 일단 전체를 구하고
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (sum2[n] - arr[i])*arr[i];
	}
	ans /= 2;
	// 완전 그래프라면 그냥 출력
	if (n == 3 || n==k) {
		printf("%I64d\n", ans);
		return 0;
	}
	// 없애야 하는 간선 계산
	ll tt = 0;
	for (int i = 1; i <= n; i++) {
		if (cap[i] == 1) continue;
		ll t = sum2[n] - arr[i - 1] - arr[i] - arr[i + 1];
		t -= cap_sum[n];
		if (cap[i - 1] == 1) t += arr[i - 1];
		if (cap[i + 1] == 1) t += arr[i + 1];
		t *= arr[i];
		tt += t;
	}

	ans -= tt/2;

	printf("%I64d\n", ans);

	return 0;
}