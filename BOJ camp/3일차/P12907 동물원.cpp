#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>

int N;
int arr[41], count[41];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
		count[arr[i]]++;
	}

	bool ok = true;
	if (count[0] > 2) ok = false;
	for (int i = 1; i < 41; i++) {
		if (count[i] > count[i - 1]) ok = false;
	}
	if (ok) {
		int i = 0,ans=1;
		while (count[i] == 2) {
			ans *= 2;
			i++;
		}
		if (count[i] == 1) ans *= 2;
		printf("%d\n", ans);
	}
	else {
		printf("0\n");
	}

	return 0;
}