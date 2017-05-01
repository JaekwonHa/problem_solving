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

int arr[51];

int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n, [](int a, int b) {
		return a > b;
	});
	int point = arr[m - 1];
	int ans = 0;
	int i = 0;
	while (point <= arr[i] && arr[i]>0) {
		ans++, i++;
	}
	printf("%d\n", ans);

	return 0;
}