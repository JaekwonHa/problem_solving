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

int n, m;
int row[100001], col[100001];
vector<ll> ans;

int main() {

	scanf("%d %d", &n, &m);
	ll sum = (ll)n*n;
	int rowCnt = 0, colCnt = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		int t = 0;
		if (row[a] == 0) t += n - colCnt;
		if (col[b] == 0) t += n - rowCnt;
		if (row[a] == 0 && col[b] == 0) t--;

		if (row[a] == 0) row[a]++, rowCnt++;
		if (col[b] == 0) col[b]++, colCnt++;
		
		sum -= t;

		ans.push_back(sum);
	}

	for (auto a : ans) {
		printf("%I64d ", a);
	}

	return 0;
}