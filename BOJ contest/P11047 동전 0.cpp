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


int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	int *arr = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (k >= arr[i]) {
			int d = k / arr[i];
			k -= d*arr[i];
			ans += d;
		}
	}
	printf("%d\n", ans);

	return 0;
}