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

char N1[101], N2[101];
char ans1[201];
char ans2[201];

int main() {

	freopen("input.txt", "r", stdin);

	int n1, n2, T;
	scanf("%d %d", &n1, &n2);
	scanf("%s %s", N1, N2);
	scanf("%d", &T);

	int top = 0;
	for (int i = n1 - 1; i >= 0; i--) {
		ans1[top++] = N1[i];
	}
	for (int i = 0; i < n2; i++) {
		ans1[top++] = N2[i];
	}
	int j = n1;
	int t = max(T - n1 + 1,0);
	for (int i = 0; i < n1; i++) {
		int plus = min(t, n2);
		ans2[i + plus] = ans1[i];
		if (j <= T+1) t++;
		j--;
	}

	t = max(T - n2 + 1,0);
	j = n2;
	for (int i = n1+n2-1; i >= n1; i--) {
		int plus = min(t, n1);
		ans2[i - plus] = ans1[i];
		if (j <= T + 1) t++;
		j--;
	}

	printf("%s\n", ans2);

	return 0;
}