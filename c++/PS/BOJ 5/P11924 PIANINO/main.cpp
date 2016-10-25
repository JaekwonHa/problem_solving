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
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

int N, arr[1000010];
set<int> v;
map<int, int> m;

int f(int a) {
	int t = arr[0];
	int ret = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] > t) t += a;
		else if (arr[i] < t) t -= a;
		if (t == arr[i]) ret++;
	}
	return ret;
}

int main() {

	scanf("%d", &N);
	scanf("%d", &arr[0]);
	int x = 0, aa=0;
	for (int i = 1; i < N; i++) {
		scanf("%d", &arr[i]);
		// 값이 감소
		if (arr[i] - arr[i - 1] < 0) {
			x--;
		// 값이 증가
		}
		else if (arr[i] - arr[i - 1] > 0) {
			x++;
		}
		if (x == 0) {
			if (arr[i] == arr[0]) aa++;
		}
		else {
			if ((arr[i] - arr[0]) % x != 0) continue;
			m[(arr[i] - arr[0]) / x]++;
		}
	}

	int ans = 0, cnt = 0;
	for (auto a : m) {
		if (cnt < a.second) {
			cnt = a.second;
			ans = a.first;
		}
	}
	printf("%d\n%d\n", cnt+aa+1, ans);

	return 0;
}