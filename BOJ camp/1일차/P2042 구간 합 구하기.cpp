#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 1000010

int N, M, K,sz;
int g[1000010];
int s[1000010];
int e[1000010];

int arr[1000010];
long long sum[1000010];

int main() {

	scanf("%d %d %d", &N, &M, &K);
	sz = sqrt(N);
	for (int i = 0; i < MAXN; i++) s[i] = -1;
	for (int i = 0; i <= N; i++) {
		g[i] = i / sz;
		if (s[g[i]] == -1) s[g[i]] = i;
		e[g[i]] = i;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum[g[i]] += arr[i];
	}
	int a, b, c;
	

	for (int i = 0; i < M + K; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			b--;
			sum[g[b]] += c - arr[b];
			arr[b] = c;
		}
		else {
			b--, c--;
			long long ans = 0;
			for (int j = b; j <= c; j++) {
				if (s[g[j]] == j && e[g[j]] <= c) {
					//operation for a brunch
					ans += sum[g[j]];
					j = e[g[j]];
				}
				else {
					//operation for a unit
					for (int k = j; k <= c && k<=e[g[j]]; k++) {
						ans += arr[k];
					}
					j = e[g[j]];
				}
			}
			printf("%lld\n", ans);
		}
	}


	return 0;
}
