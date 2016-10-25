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

int n,m,a;
int arr[500001];

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a);
		int lb = 0, ub = n - 1, md;
		while (lb <= ub) {
			md = (lb + ub) / 2;
			if (arr[md] > a) ub = md-1;
			else lb = md + 1;

			if (arr[md] == a) break;
		}
		if (arr[md] == a) printf("1\n");
		else printf("0\n");
	}

	return 0;
}