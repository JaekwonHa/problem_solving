#include <stdio.h>
#include <algorithm>

int N;
int cnt[55];

int main() {
	scanf("%d", &N);

	int a;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		cnt[a]++;
	}
	int ans = 0;
	for (int k = 1; k <= N; k++) {
		int t = 1;
		for (int i = 1; i <= k; i++) t *= cnt[i];
		ans += t;
	}
	printf("%d\n", ans);
	return 0;
}