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
int c[1000001];
int w[1000001];

int main() {


	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < n; i++) scanf("%d", &w[i]);

	double ans = 1e100;
	for (int i = 0; i < n; i++) {
		double sum = 0;
		double x = w[i] / (double)c[i];
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			sum += abs(x*c[j] - w[j]);
		}
		ans = min(ans, sum);
	}

	printf("%0.9lf\n", ans);

	return 0;
}