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
pair<int,int> mos[21];

int main() {
	int x1=INF, y1=INF, x2=0, y2=0, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		x1 = min(x1, a);
		y1 = min(y1, b);
		x2 = max(x2, a);
		y2 = max(y2, b);
	}
	int t = max(x2 - x1, y2 - y1);
	printf("%d\n", t*t);

	return 0;
}