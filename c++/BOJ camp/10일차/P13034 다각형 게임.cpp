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

int g[1001];
int gn[1001];

int main() {

	int N;
	scanf("%d", &N);

	g[2] = 1;
	for (int i = 3; i <= N; i++) {
		for (int j = 0; j <= (i - 2); j++) {
			gn[g[j] ^ g[i - 2 - j]] = 1;
		}
		for (int j = 0; j < 1000; j++) {
			if (gn[j] == 0) {
				g[i] = j;
				break;
			}
		}
		memset(gn, 0, sizeof(gn));
	}
	printf("%d\n", g[N] == 0 ? 2 : 1);
	return 0;
}

