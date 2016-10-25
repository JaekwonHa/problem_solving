#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N, arr[10001];
int DP[2][5001][2];

int main() {

	scanf("%d", &N);
	for (int i = 1; i < N; i++) scanf("%d", arr + i);

	memset(DP, 0x3f, sizeof(DP));

	int t = 0;
	DP[1][1][1] = 0;
	for (int pos = 2; pos <= N; pos++, t = !t) {
		memset(DP + !t, 0x3f, sizeof(DP[!t]));
		for (int i = 1; i <= min(pos, N / 2); i++) {
			// 내가 가지는 경우
			DP[!t][i][1] = min(DP[t][i - 1][1], DP[t][i - 1][0] + arr[pos-1]);
			// 도토리를 주는 경우
			DP[!t][i][0] = min(DP[t][i][0], DP[t][i][1] + arr[pos-1]);
		}
	}

	printf("%d\n", min(DP[t][N / 2][0], DP[t][N / 2][1]));

	return 0;
}

