#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int P1, P2, P3, X1, X2, X3, N;
	scanf("%d %d %d %d %d %d", &P1, &P2, &P3, &X1, &X2, &X3);

	for (N = 1; N < 27000000; N++) {
		if (N%P1 == X1 && N%P2 == X2 && N%P3 == X3) {
			printf("%d\n", N);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}

