#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
#define H 0
#define L 1

int N, DP[55][3][3];
char people[55];

int f(int pos, int first, int current) {
	if (pos == N) {
		if (first != current) return INF;
		if (current == L) return -1;
		return 0;
	}

	int &ret = DP[pos][first][current];
	if (ret != -1) return ret;

	if (people[pos] == 'H') {
		if (current == H) ret = f(pos + 1, first, H);
		if (current == L) ret = f(pos + 1, first, L) + 1;
	}
	else if (people[pos] == 'L') {
		if (current == H) ret = f(pos + 1, first, L) + 1;
		if (current == L) ret = f(pos + 1, first, H);
	}
	else {
		ret = min(f(pos + 1, first, L) + 1, f(pos + 1, first, H));
	}
	return ret;
}

int main() {

	scanf("%d %s", &N, people);
	memset(DP, -1, sizeof(DP));
	int ans;
	ans = min(f(0, H, H), f(0, L, L) + 1);

	if (ans > 100) ans = -1;

	printf("%d\n", ans);

	return 0;
}

