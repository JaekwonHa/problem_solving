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

int n;

int combi(int n, int r) {
	if (n == r) return 1;
	if (r == 1) return n;

	return combi(n - 1, r) + combi(n - 1, r - 1);
}

int main() {

	
	scanf("%d", &n);
	if (n == 3) {
		printf("0\n");
	}
	else {
		printf("%d\n", combi(n, 4));
	}

	return 0;
}