#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int ans = 0,consecutive=0;
	int N, D;
	char input[101];
	scanf("%d %d", &N, &D);
	for (int i = 0; i < D; i++) {
		scanf("%s", input);
		int j;
		for (j = 0; j < N; j++) {
			if (input[j] == '0') break;
		}
		if (j != N) consecutive++;
		else consecutive = 0;
		ans = consecutive > ans ? consecutive : ans;
	}
	printf("%d\n", ans);

	return 0;
}