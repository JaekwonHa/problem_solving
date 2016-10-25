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
	int idx, num;
};

int main() {

	Point arr[3];
	char a[4];
	int ans[3];

	scanf("%d %d %d", &arr[0].num, &arr[1].num, &arr[2].num);
	scanf("%s", a);

	sort(arr, arr + 3, [](Point a, Point b) {
		return a.num < b.num;
	});

	arr[0].idx = 0;
	arr[1].idx = 1;
	arr[2].idx = 2;


	printf("%d %d %d\n", arr[a[0] - 'A'].num, arr[a[1] - 'A'].num, arr[a[2] - 'A'].num);

	return 0;
}