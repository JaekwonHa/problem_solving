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

	int n;
	scanf("%d", &n);
	char a[101];
	for (int i = 0; i < n; i++) {
		scanf("%s", a);
		int len = strlen(a);
		if (len > 10) {
			printf("%c%d%c\n", a[0], len - 2, a[len - 1]);
		}
		else {
			printf("%s\n", a);
		}
	}

	return 0;
}