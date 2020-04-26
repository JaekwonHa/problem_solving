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

struct Point {
	ll to, sum, min;
	Point(ll a, ll b, ll c) : to(a), sum(b), min(c) {
	}
	Point() {
	}
};

ll n, k;
Point arr[100001];
Point ans[100001];

void multiplyArr(Point arr1[], Point arr2[]) {
	Point *ret = new Point[n];
	
	for (int i = 0; i < n; i++) {
		ret[i].sum = arr1[i].sum + arr2[arr1[i].to].sum;
		ret[i].min = min(arr1[i].min, arr2[arr[i].to].min);
		ret[i].to = arr2[arr1[i].to].to;
	}
	for (int i = 0; i < n; i++) arr2[i] = ret[i];
}

int main() {

	scanf("%I64d %I64d", &n, &k);
	int a;
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &arr[i].to);
	}
	for (int i = 0; i < n; i++) {
		scanf("%I64d", &arr[i].sum);
		arr[i].min = arr[i].sum;
		ans[i] = arr[i];
	}
	k--;
	while (k) {
		if (k & 1) {
			multiplyArr(arr, ans);
		}
		multiplyArr(arr, arr);
		k >>= 1;
	}

	for (int i = 0; i < n; i++) {
		printf("%I64d %I64d\n", ans[i].sum, ans[i].min);
	}

	return 0;
}