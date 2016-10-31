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
	int idx, n;
	bool operator < (const Point a) const {
		return n > a.n;
	}
};
#define MAX 100001
int n, half;
Point arr[301];
int DP[MAX];
int p[MAX];
int s[MAX];


int main() {

	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i].n);
		arr[i].idx = i;
		sum += arr[i].n;
	}
	half = sum / 2;

	sort(arr+1, arr + n+1);

	DP[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = sum; j >= arr[i].n; j--) {
			if (j - arr[i].n <= half && DP[j - arr[i].n] == 1 && DP[j]==0) {
				DP[j] = 1;
				p[j] = j - arr[i].n;
				s[j] = arr[i].idx;
			}
		}
	}
	for (int i = sum; i >= 0; i--) {
		if (DP[i] == 1) {
			int cnt = 1;
			int t = i;
			while (p[t] != 0) t = p[t], cnt++;
			printf("%d\n", cnt);
			t = i;
			while (p[t] != 0) {
				printf("%d ", s[t]);
				t = p[t];
			}
			printf("%d ", s[t]);
			break;
		}
	}

	return 0;
}