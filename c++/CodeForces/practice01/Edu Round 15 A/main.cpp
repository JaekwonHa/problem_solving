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
int arr[1000000];
int DP[1000000];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	int ans = 1;
	DP[0] = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] > arr[i - 1]) DP[i] = DP[i - 1] + 1;
		else DP[i] = 1;
		ans = max(ans, DP[i]);
	}

	printf("%d\n", ans);

	return 0;
}