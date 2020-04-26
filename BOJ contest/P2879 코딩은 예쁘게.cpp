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
#define p 1000000007
typedef long long ll;

int N;
int arr[1010], arr1[1010], arr2[1010];

int f(int left, int right) {
	if (left > right) return 0;
	if (left == right) {
		int ret = abs(arr[left]);
		arr[left] = 0;
		return ret;
	}

	int minV = INF;
	int mid = 0;
	for (int i = left; i <= right; i++) {
		if (minV > arr[i]) {
			minV = arr[i];
			mid = i;
		}
	}
	for (int i = left; i <= right; i++) {
		arr[i] -= minV;
	}
	return abs(minV) + f(left, mid - 1) + f(mid + 1, right);
}

int f2(int left, int right) {
	if (left > right) return 0;
	if (left == right) {
		int ret = abs(arr[left]);
		arr[left] = 0;
		return ret;
	}

	int maxV = -INF;
	int mid = 0;
	for (int i = left; i <= right; i++) {
		if (maxV < arr[i]) {
			maxV = arr[i];
			mid = i;
		}
	}
	for (int i = left; i <= right; i++) {
		arr[i] -= maxV;
	}
	return abs(maxV) + f2(left, mid - 1) + f2(mid + 1, right);
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr1[i];
	for (int i = 0; i < N; i++) cin >> arr2[i];
	for (int i = 0; i < N; i++) {
		arr[i] = arr1[i] - arr2[i];
	}
	int ans = 0;
	int left = 0, right = 0, type = 1;
	if (arr[0] < 0) type = -1;
	else type = 1;

	for (int i = 1; i < N; i++) {
		if (type == -1 && arr[i] > 0) {
			ans += f2(left, i - 1);
			left = i;
			type = 1;
		}
		else if (type == 1 && arr[i] < 0) {
			ans += f(left, i - 1);
			left = i;
			type = -1;
		}
	}
	if (abs(arr[N - 1]) >= 0 && arr[N-1]<=0) {
		ans += f2(left, N - 1);
	}
	else if (abs(arr[N - 1]) >= 0 && arr[N - 1] >= 0) {
		ans += f(left, N - 1);
	}

	cout << ans << endl;

	return 0;
}