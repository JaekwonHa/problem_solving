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

int arr[1001];

int main() {

	int N, C, ans = 0;
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		int t = 0, j = i, cnt=0;
		while (j < N && t < C) {
			if (t + arr[j] <= C) t += arr[j], cnt++;
			j++;
		}
		ans = max(ans, cnt);
	}

	printf("%d\n", ans);

	return 0;
}