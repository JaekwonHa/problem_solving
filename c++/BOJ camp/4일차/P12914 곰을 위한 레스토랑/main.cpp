#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <deque>
#include <stack>
#include <queue>

int N, D;
int arr[1010];
long long list[1010];
long long chair[1010];

int main() {
	scanf("%d %d", &N, &D);
	for (int i = 0; i < N; i++) scanf("%d", arr + i);

	chair[0] = arr[0];
	list[0] = arr[0];

	for (int i = 1; i < N; i++) {
		int j = 0;
		while (j<i) {
			if (arr[i] < chair[j] + D && chair[j] - D < arr[i]) {
				arr[i] = chair[j] + D;
			}
			j++;
		}

		list[i] = arr[i];
		chair[i] = arr[i];
		std::sort(chair, chair + i+1);
	}

	for (int i = 0; i < N; i++) {
		if (i != 0) printf(" ");
		printf("%lld", list[i]);
	}
	printf("\n");


	return 0;
}