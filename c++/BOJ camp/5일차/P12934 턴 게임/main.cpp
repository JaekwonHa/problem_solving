#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main() {

	long long x, y;
	scanf("%lld %lld", &x, &y);

	long long n = sqrt(2*(x+y));
	long long sum;
	while (1) {
		sum = ((1 + n)*n) / 2;
		if (x + y == sum) break;
		if (x + y < sum) {
			printf("-1\n");
			return 0;
		}
		n++;
	}

	int ans = 0;
	while (0<x) {
		if (x >= n) x -= n, ans++;
		n--;
	}
	printf("%d\n", ans);

	return 0;
}

