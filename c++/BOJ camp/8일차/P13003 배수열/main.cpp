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

int N, L;
long long DP[2010][2010];

ll f(int pos, int last) {
	ll &ret = DP[pos][last];
	if (ret != -1) return ret;

	if (pos == L-1) return ret = 1;

	ret = 0;
	for (int i = 1; last*i <= N; i++) {
		ret = (ret + f(pos + 1, last*i)) % p;
	}
	return ret;
}

int main() {

	scanf("%d %d", &N, &L);

	ll ans = 0;
	memset(DP, -1, sizeof(DP));
	for (int i = 1; i <= N; i++) {
		ans = (ans + f(0, i)) % p;
	}
	printf("%lld\n", ans);

	return 0;
}

