#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;

int N, C[51], W[51];

double f(double d) {
	double ret = 0;
	for (int i = 0; i < N; i++) {
		ret += abs(W[i] - d);
	}
	return ret;
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &C[i]);
	for (int i = 0; i < N; i++) scanf("%d", &W[i]);

	double ans = 1e9;
	for (int i = 0; i < N; i++) {
		double d = W[i] / C[i];
		ans = min(ans, f(d));
	}

	printf("%.f\n", ans);

	return 0;
}

