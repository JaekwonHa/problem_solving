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
#include <set>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

int N, S;
int arr[21];

int main() {

	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	int ans = 0;
	for (int k = 1; k <= (1 << N) - 1; k++) {
		int sum = INF;
		for (int i = 0; i < N; i++) {
			if (k&(1 << i)) {
				if (sum == INF) sum = arr[i];
				else sum += arr[i];
			}
		}
		if (sum == S) {
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}