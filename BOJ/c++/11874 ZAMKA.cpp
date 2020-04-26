#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <stack>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;


bool f(int n, int X) {
	int ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret == X;
}

int main() {

	int L, N, M, D, X;
	scanf("%d %d %d", &L, &D, &X);

	for (int i = L; i <= D; i++) {
		if (f(i, X)) {
			N = i;
			break;
		}
	}

	for (int i = D; i >= L; i--) {
		if (f(i, X)) {
			M = i;
			break;
		}
	}

	printf("%d\n%d", N, M);

	return 0;
}