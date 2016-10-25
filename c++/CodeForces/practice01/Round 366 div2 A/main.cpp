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

	for (int i = 0; i <= n; i++) {
		if (i != 0) {
			if (i == n) {
				printf(" it\n");
				break;
			}
			else {
				printf(" that ");
			}
		}
		
		if (i % 2 == 0) {
			printf("I hate");
		}
		else {
			printf("I love");
		}
	}

	return 0;
}