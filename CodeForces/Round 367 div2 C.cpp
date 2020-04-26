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


#define INF 98765432100000
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n;
int arr[100010];
string str1, str2, str1_re, str2_re;
ll DP[100010][2];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	cin >> str1;
	DP[0][0] = 0;
	DP[0][1] = arr[0];
	for (int i = 1; i < n; i++) {
		cin >> str2;
		DP[i][0] = DP[i][1] = INF;

		str1_re = str1;
		reverse(str1_re.begin(), str1_re.end());
		str2_re = str2;
		reverse(str2_re.begin(), str2_re.end());

		// 현재것을 reverse
		if (str1.compare(str2_re) <= 0) {
			DP[i][1] = min(DP[i][1], DP[i - 1][0] + arr[i]);
		}
		// 둘다 reverse
		if (str1_re.compare(str2_re) <= 0) {
			DP[i][1] = min(DP[i][1], DP[i - 1][1] + arr[i]);
		}
		// 이전것을 reverse
		if (str1_re.compare(str2) <= 0) {
			DP[i][0] = min(DP[i][0], DP[i - 1][1]);
		}
		if (str1.compare(str2) <= 0) {
			DP[i][0] = min(DP[i][0], DP[i - 1][0]);
		}

		str1 = str2;
	}
	ll ans = min(DP[n - 1][0], DP[n - 1][1]);
	if (ans == INF) ans = -1;
	printf("%I64d\n", ans);

	return 0;
}