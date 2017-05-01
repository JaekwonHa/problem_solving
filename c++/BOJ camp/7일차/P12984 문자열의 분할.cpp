#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, K;
int DP[1010][1010][12][2];
char A[1010], B[1010];

int f(int pos1, int pos2, int k, int type) {
	int &ret = DP[pos1][pos2][k][type];
	if (ret != -1) return ret;
	
	ret = 0;
	if (k == 0) return ret;
	if (pos1 >= strlen(A) || pos2 >= strlen(B)) return ret;

	if (A[pos1] == B[pos2]) {
		if (type > 0) {
			ret = max(ret, f(pos1 + 1, pos2 + 1, k, 1) + 1);
		}
		else {
			ret = max(ret, f(pos1 + 1, pos2 + 1, k-1, 1) + 1);
		}
	}
	ret = max(ret, f(pos1 + 1, pos2, k, 0));
	ret = max(ret, f(pos1, pos2 + 1, k, 0));

	return ret;
}

int main() {

	scanf("%d %d %d", &N, &M, &K);

	scanf("%s %s", A+1, B+1);
	A[0] = ' ', B[0] = ' ';
	/*
	memset(DP, -1, sizeof(DP));
	printf("%d\n", f(0, 0, K, 0));
	*/
	memset(DP, 0, sizeof(DP));
	for (int pos1 = 1; pos1 <= strlen(A); pos1++) {
		for (int pos2 = 1; pos2 <= strlen(B); pos2++) {
			for (int k = 1; k <= K; k++) {
				if (A[pos1] == B[pos2]) {
					DP[pos1][pos2][k][1] = max(DP[pos1 - 1][pos2 - 1][k][1] + 1, DP[pos1 - 1][pos2 - 1][k - 1][0] + 1);
					//DP[pos1][pos2][k][1] = max(DP[pos1][pos2][k][1], DP[pos1 - 1][pos2 - 1][k - 1][1] + 1);
				}
				DP[pos1][pos2][k][0] = max(DP[pos1][pos2 - 1][k][0], DP[pos1 - 1][pos2][k][0]);
				//DP[pos1][pos2][k][0] = max(DP[pos1][pos2][k][0], DP[pos1 - 1][pos2 - 1][k][0]);
				DP[pos1][pos2][k][0] = max(DP[pos1][pos2][k][0], DP[pos1 - 1][pos2][k][1]);
				DP[pos1][pos2][k][0] = max(DP[pos1][pos2][k][0], DP[pos1][pos2 - 1][k][1]);
			}
		}
	}
	printf("%d\n", DP[strlen(A)][strlen(B)][K][0]);
	return 0;
}

