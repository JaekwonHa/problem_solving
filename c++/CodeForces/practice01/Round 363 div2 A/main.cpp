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
#include <deque>
#include <functional>
using namespace std;

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n;
char dir[200001];
int x[200001];

int main() {
	int ans = INF;
	scanf("%d", &n);
	scanf("%s", dir);
	scanf("%d", &x[0]);
	for (int i = 1; i < n; i++) {
		scanf("%d", &x[i]);
		if (dir[i - 1] == 'R' && dir[i] == 'L') {
			ans = min(ans, (x[i] - x[i - 1])/2);
		}
	}
	if (ans == INF) ans = -1;
	printf("%d\n", ans);

	return 0;
}