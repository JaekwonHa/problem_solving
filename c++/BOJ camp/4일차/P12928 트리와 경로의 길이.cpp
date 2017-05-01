#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int N, S;
int DP[51][51][1001];

void f(int n, int o, int s) {
	if (DP[n][o][s] != -1) return;
	DP[n][o][s] = 1;

	int ns;
	for (int i = 1; n + i <= N; i++) {
		ns = s + i + i*(i - 1) / 2;
		if (ns > S) break;
		f(n + i, o - 1 + i, ns);
	}
}

int main() {

	scanf("%d %d", &N, &S);

	memset(DP, -1, sizeof(DP));
	int n=N, s=S, ns=0;
	for (int i = 1; 1+i <= N; i++) {
		n = 1 + i;
		s = (n - 2)*(n - 1) / 2;
		f(n, n-1, s);
	}

	for (int i = 1; i <= N; i++) {
		if (DP[N][i][S] == 1) {
			printf("1\n");
			return 0;
		}
	}
	printf("0\n");
	return 0;
}

