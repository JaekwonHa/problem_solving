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

int prime[1500];

int main() {

	int N;
	prime[1] = 1;
	for (int i = 2; i <= 1100; i++) {
		if(prime[i] == 1) continue;
		for (int j = i * 2; j <= 1100; j += i) {
			prime[j] = 1;
		}
	}
	int ans = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		if (prime[a] == 0) ans++;
	}
	printf("%d\n", ans);


	return 0;
}