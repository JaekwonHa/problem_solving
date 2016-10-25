#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;

int arr[1001];
int N, M;
map<int, int> m;

int main() {

	scanf("%d %d", &N, &M);
	int a, b;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		for (int j = a; j <= b; j++) {
			arr[j] = i + 1;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) continue;
		m[arr[i]]++;
	}
	long long ans = pow(2, m.size());
	printf("%lld\n", ans);

	return 0;
}

