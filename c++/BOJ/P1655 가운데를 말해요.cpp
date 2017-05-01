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
#include <set>
#include <stack>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;


int main() {

	freopen("input.txt", "r", stdin);

	int n,a;
	scanf("%d", &n);
	multiset<int> ms;
	scanf("%d", &a);
	ms.insert(a);
	auto it = ms.find(a);
	printf("%d\n", *it);
	for (int i = 2; i <= n; i++) {
		scanf("%d", &a);
		ms.insert(a);
		if (*it <= a) {
			if (i % 2 == 1)
				it++;
		}
		else {
			if (i % 2 == 0)
				it--;
		}
		printf("%d\n", *it);
	}
	return 0;
}