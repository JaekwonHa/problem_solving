#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<algorithm>

int N,M;
int arr[10001];

int main() {
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &M);

	std::sort(arr, arr + N);

	int t = 0, i;
	for (i = 0; i < N && t + (N - i)*arr[i] <= M; i++) {
		t += arr[i];
	}
	printf("%d\n", (i == N) ? arr[N - 1] : (M - t) / (N - i));

	return 0;
}