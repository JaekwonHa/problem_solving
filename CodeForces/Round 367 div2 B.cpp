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

int n, q;
int arr[100100];
int sum[100100];
map<int, int> m;

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		m[t]++;
	}
	auto a = m.begin();
	int cnt = 0;
	for (int i = 1; i <= n && a!=m.end(); i++) {
		arr[i] = a->first;
		sum[i] = sum[i - 1] + a->second;
		a++;
		cnt++;
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int t;
		scanf("%d", &t);

		int lb = 1, ub = cnt;
		
		while (lb <= ub) {
			int md = (lb + ub) / 2;
			if (arr[md] < t) lb = md + 1;
			else ub = md - 1;

			if (arr[md] == t) {
				lb = md;
				break;
			}
		}
		if (arr[lb] > t) lb--;
		if (arr[cnt] < t) lb = cnt;
		printf("%d\n", sum[lb]);
	}

	return 0;
}