#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
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
#define mod 1000000007
typedef long long ll;


int main() {

	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	int a, b, k;
	int ans = INF;
	k = abs(G - S);

	if (S == G) {
		printf("0\n");
		return 0;
	}
	if (U == 0 && D == 0) {
		printf("use the stairs\n");
		return 0;
	}
	if (U == 0) {
		if (S<G) {
			printf("use the stairs\n");
			return 0;
		}
		else {
			if (k%D == 0) {
				printf("%d\n", k / D);
				return 0;
			}
			else {
				printf("use the stairs\n");
				return 0;
			}
		}
	}
	if (D == 0) {
		if (S>G) {
			printf("use the stairs\n");
			return 0;
		}
		else {
			if (k%U == 0) {
				printf("%d\n", k / U);
				return 0;
			}
			else {
				printf("use the stairs\n");
				return 0;
			}
		}
	}
	else if (S > G) {
		swap(U, D);
	}
	for (a = 1; a <= 1000000; a++) {
		if (U*a - k < 0) continue;
		if ((U*a - k) % D == 0) {
			ans = min(ans, abs(a + (U*a - k) / D));
		}
	}
	if (ans == INF) {
		printf("use the stairs\n");
	}
	else {
		printf("%d", ans);
	}
	return 0;
}