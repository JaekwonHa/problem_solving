#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, W[5100];
int DP[5100];
double arr[5100];

int solve() {
	memset(DP, -1, sizeof(DP));
	int ans = 0;
	DP[0] = W[0];
	for (int i = 1; i<N; i++) {
		DP[i] = W[i];
		for (int j = 0; j<i; j++) {
			if (arr[j] - (1e-9) <= arr[i] && DP[i] < DP[j] + W[i]) {
				DP[i] = DP[j] + W[i];
			}
		}
		ans = max(ans, DP[i]);
	}
	return ans;
}

int main() {
	int sum = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &W[i]);
		sum += W[i];
	}
	int ans = sum - solve();
	cout << ans << endl;

	return 0;
}
