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

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;


int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	int ans;
	if (n == 1) {
		ans = 1;
	}
	else if (n == 2) {
		if (m < 2) ans = 1;
		else {
			ans = min(4, (m + 1) / 2);
		}
	}
	else {
		if (m <= 4) ans = m;
		else if (m <=6) ans = 4;
		else {
			ans = m - 2;
		}
	}
	cout << ans;
	return 0;
}