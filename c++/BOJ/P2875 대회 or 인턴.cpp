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


int main() {

	int n, m, k;
	int team, r;
	scanf("%d %d %d", &n, &m, &k);

	if (n / 2 >= m) {
		team = m;
		r = n - 2 * team;
	}
	else {
		team = n / 2;
		r = m - team + n - 2 * team;
	}
	k -= r;
	if (k > 0) {
		team = team - (k + 2) / 3;
	}
	printf("%d\n", team);

	return 0;
}