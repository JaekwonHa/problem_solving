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

ll n, ans;
int arr[500001];
int o[500001];

void Merge(int s, int e) {
	int idx = s;
	int left = s, mid = (s + e) / 2 + 1;

	while (left <= (s + e) / 2 && mid <= e) {
		if (arr[left] > arr[mid]) {
			ans += mid - idx;
			o[idx] = arr[mid];
			idx++, mid++;
		}
		else {
			o[idx] = arr[left];
			idx++, left++;
		}
	}
	while (left <= (s + e) / 2) o[idx++] = arr[left++];
	while (mid <= e) o[idx++] = arr[mid++];

	for (int i = s; i <= e; i++)
		arr[i] = o[i];
}

void Divide(int s, int e) {
	if (s < e) {
		int md = (s + e) / 2;
		Divide(s, md);
		Divide(md + 1, e);
		Merge(s, e);
	}
}

int main() {

	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	Divide(0, n - 1);

	printf("%lld\n", ans);

	return 0;
}