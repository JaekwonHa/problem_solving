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

int fib[50];

void makeFib() {
	fib[0] = 0, fib[1] = 1;
	for (int i = 2; i <= 50; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] >= 1000000000) break;
	}
}

int main() {

	freopen("input.txt", "r", stdin);

	makeFib();

	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		stack<int> s;
		for (int i = 45; i >= 1; i--) {
			if (fib[i] == 0) continue;
			if (fib[i] <= N) {
				s.push(fib[i]);
				N -= fib[i];
			}
		}
		while (!s.empty()) {
			printf("%d ", s.top());
			s.pop();
		}
		printf("\n");
	}

	return 0;
}