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

#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n, m;
int city[1000000];
int tower[1000000];

int main() {

	int input;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &city[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &tower[i]);
	}

	sort(city, city + n);
	sort(tower, tower + m);

	int j = 0;
	ll ans = 0,t = 0;
	for (int i = 0; i < n; i++) {
		while (j!=m-1 && abs(tower[j] - city[i]) >= abs(tower[j + 1] - city[i])) {
			j++;
		}
		t = abs(tower[j] - city[i]);
		ans = max(ans, t);
	}

	printf("%I64d\n", ans);

	return 0;
}