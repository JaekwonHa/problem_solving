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

int arr[1010];
int DP[1010];

int main() {

	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]), DP[i] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) {	
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) ans = max(ans, DP[i]);
	printf("%d\n", ans);
	return 0;
}