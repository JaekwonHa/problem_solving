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


int main() {

	int s, t, x;
	scanf("%d %d %d", &t, &s, &x);
	x -= t;
	bool ok = false;
	
	if (x < 0) {

	}
	else if (x == 0) {
		ok = true;
	}
	else if (x == 1) {

	}
	else if (x%s == 0 || (x - 1) % s == 0) {
		ok = true;
	}

	ok ? printf("YES\n") : printf("NO\n");

	return 0;
}