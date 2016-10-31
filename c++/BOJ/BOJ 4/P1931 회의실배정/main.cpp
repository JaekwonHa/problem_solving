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

int n;
pair<int, int> arr[100001];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &arr[i].first, &arr[i].second);

	sort(arr, arr + n, [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second) return a.first < b.first;
		return a.second < b.second;
	});
	int ans = 1;
	int start = arr[0].second;
	for (int i = 1; i < n; i++) {
		if (start <= arr[i].first) {
			ans++;
			start = arr[i].second;
		}
	}
	printf("%d\n", ans);

	return 0;
}