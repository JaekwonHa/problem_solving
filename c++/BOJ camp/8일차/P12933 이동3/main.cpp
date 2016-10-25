#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321

long long N, S;
long long X, Y;

int f(long long x, long long y, int n) {
	if (x == X && y == Y) return 1;
	if (x > X || x<0 || y>Y || y < 0) return 0;
	if (n > N) return 0;

	int ret = f(x + pow(3, n), y, n + 1);
	if (ret) return ret;

	ret = f(x, y + pow(3, n), n + 1);
	return ret;
}

int main() {

	
	scanf("%lld %lld", &X, &Y);

	if (X == 0 && Y == 0) {
		printf("1\n");
		return 0;
	}
	
	N = 1;
	while (1) {
		S = (pow(3, N) - 1) / 2;
		if (X + Y == S) break;
		if (X + Y < S) {
			printf("0\n");
			return 0;
		}
		N++;
	}
	N--;

	printf("%d\n", f(0, 0, 0));

	return 0;
}