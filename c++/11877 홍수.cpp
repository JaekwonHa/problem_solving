#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string>
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

long long N, number;
long long X;
bool ans[1000001];

void solve() {
	long long sum = ((N - 1)*(N - 2)) / 2;
	long long height = N - 1;

	for (int i = 1; i <= N - 2; i++) {
		if (sum - (height - i) >= X) {
			sum = sum - (height - i);
			ans[i] = true;
		}
		if (sum == 0) return;
	}
}

int main() {

	scanf("%lld %lld", &N, &X);

	if (N<3LL) {
		if (X != 0LL) puts("-1");
		else for (int i = 1; i <= N; i++) printf("%d ", i);
		return 0;
	}
	
	long long maxFlow = ((N - 1)*(N - 2)) / 2;
	if (maxFlow < X) {
		printf("-1\n");
		return 0;
	}

	solve();
	for (int i = 1; i <= N; i++) {
		if (ans[i] == true) printf("%d ", i);
	}
	printf("%lld ", N);
	for (int i = 1; i <= N-2; i++) {
		if (ans[i] == false) printf("%d ", i);
	}
	printf("%lld\n", N-1);

	return 0;
}