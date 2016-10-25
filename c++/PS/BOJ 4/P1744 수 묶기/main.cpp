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

int n, arr[10010];

int main() {
	int zero = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 0) zero++;
	}

	sort(arr, arr + n);
	int i = 0;
	ll ans = 0;
	while (arr[i]<0) {
		if (arr[i] < 0 && arr[i + 1] < 0 && arr[i]-arr[i+1]==-1) {
			ans += arr[i] * arr[i + 1];
			i += 2;
			continue;
		}
		if (zero > 0) {
			i++;
			zero--;
			continue;
		}
		ans += arr[i];
		i++;
	}
	i = n - 1;
	while (arr[i]>0) {
		if (arr[i] > 0 && arr[i - 1]>0 && arr[i]-arr[i-1]==1) {
			ans += arr[i] * arr[i - 1];
			i -= 2;
			continue;
		}
		ans += arr[i];
		i--;
	}
	printf("%lld\n", ans);

	return 0;
}