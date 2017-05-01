#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

long long arr[10000003];

void solve() {
	int X2 = 0, X3 = 0, value2, value3, i=0;
	arr[0] = 1;
	while (i <= 10000000) {
		value2 = arr[X2] * 2 + 1;
		value3 = arr[X3] * 3 + 1;
		if (value2 == value3) {
			arr[++i] = value2;
			X2++, X3++;
		}
		else if (value2 < value3) {
			arr[++i] = value2;
			X2++;
		}
		else {
			arr[++i] = value3;
			X3++;
		}

	}
}

int main() {

	int T, N;
	scanf("%d", &T);

	solve();

	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", arr[N-1]);
	}

	return 0;
}

