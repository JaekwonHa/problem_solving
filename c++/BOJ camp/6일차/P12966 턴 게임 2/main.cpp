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

	//long long n = sqrt(x + y-1);
	long long n = 0;
	long long sum;
	while (1) {
		sum = n*n;
		if (x + y == sum) break;
		if (x + y < sum) {
			printf("-1\n");
			return 0;
		}
		n++;
	}

	long long l = 0, r = 0;
	for (long long i = 0; i <= n; i++) {
		if ((x + i) % 2 == 0) {
			if (l <= (x + i) / 2 && (x + i) / 2 <= r) {
				printf("%lld\n", i);
				return 0;
			}
		}
		l += i + 1;
		r += n - i;		
	}
	printf("-1\n");

	return 0;
}

