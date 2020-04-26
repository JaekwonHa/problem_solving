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


int main() {

	int x, y, n, a, b, c;
	scanf("%d %d %d", &x, &y, &n);
	double ans = INF;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a, &b, &c);
		double t = sqrt((double)((x - a) * (x - a) + (y - b)*(y - b))) / c;
		ans = min(ans, t);
	}

	printf("%.10lf\n", ans);


	return 0;
}