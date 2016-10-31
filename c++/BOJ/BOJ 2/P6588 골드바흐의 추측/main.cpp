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

int prime[1000001];

int main() {

	prime[1] = 1;
	for (int i = 2; i < 1000000; i++) {
		if (prime[i] == 1) continue;
		for (int j = i * 2; j <= 1000000; j += i) {
			prime[j] = 1;
		}
	}

	while (1) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;


		/*
		int a=3, b=n;

		while (a + b != n && b>2) {
			while (prime[b] == 1 && b>2) b--;
			a = 3;
			while (a<b) {
				if (prime[a] == 0 && a + b == n) break;
				if (prime[a] == 0 && a + b>n) break;
				a++;
			}
			if (a + b != n) b--;
		}

		if (prime[a]==0 && prime[b]==0 && a + b == n) {
			printf("%d = %d + %d\n", n, a, b);
		}
		else {
			printf("Goldbach's conjecture is wrong.\n");
		}
		*/
		for (int i = 3; i <= n/2; i++) {
			if (prime[i] == 0 && prime[n - i] == 0) {
				printf("%d = %d + %d\n", n, i, n-i);
				break;
			}
		}
	}

	return 0;
}