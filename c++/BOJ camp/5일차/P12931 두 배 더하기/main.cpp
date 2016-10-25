#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int go(int arr[], int len) {
	bool ok = true, ans = true;
	for (int i = 0; i < len; i++) {
		if (arr[i] % 2 == 1) ok = false;
		if (arr[i] != 0) ans = false;
	}
	if (ans) return 0;

	int cnt = 0;
	if (ok) {
		for (int i = 0; i < len; i++) {
			arr[i] = arr[i] / 2;
		}
		cnt++;
	}
	else {
		
		for (int i = 0; i < len; i++) {
			if (arr[i] % 2 == 1) arr[i]--, cnt++;
		}
	}
	return go(arr, len) + cnt;
}

int main() {

	int N, arr[51];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", arr + i);

	printf("%d\n", go(arr, N));


	return 0;
}