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

int prime[1000010];

int main() {

	prime[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == 1) continue;
		for (int j = i * 2; j <= 1000000; j += i) {
			prime[j] = 1;
		}
	}
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) {
		if (prime[i] == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}