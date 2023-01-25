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

	int x = 0, y = 0;
	int n, a, b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a < b) y++;
		else if(a>b) x++;
	}
	if (x > y) {
		printf("Mishka\n");
	}
	else if (x == y) {
		printf("Friendship is magic!^^\n");
	}
	else {
		printf("Chris\n");
	}

	return 0;
}