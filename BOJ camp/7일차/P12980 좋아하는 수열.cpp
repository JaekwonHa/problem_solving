#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int countArr(int arr[], int N, vector<int> P) {
	int ret = 0, cnt = 0;
	int a[101];
	memcpy(a, arr, sizeof(a));
	for (int i = 0; i < N; i++) {
		if (a[i] == 0) {
			a[i] = P[cnt++];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] < a[j]) {
				ret++;
			}
		}
	}
	return ret;
}

int main() {

	vector<int> P;
	int N, S, arr[101], cnt[101];
	scanf("%d %d", &N, &S);

	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
		cnt[arr[i]]++;
	}

	for (int i = 1; i <= N; i++) if (cnt[i] == 0) P.push_back(i);

	int ans = 0;
	do {
		int ret = countArr(arr, N, P);
		if (ret == S) ans++;
	} while (next_permutation(P.begin(), P.end()));

	printf("%d\n", ans);

	return 0;
}

