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
	
	int n, L, a;
	scanf("%d %d", &n, &L);

	deque<pair<int, int>> dq;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (dq.empty()) {
		}
		else {
			while (!dq.empty() && dq.back().second > a) dq.pop_back();
			if (!dq.empty() && i - dq.front().first >= L) {
				dq.pop_front();
			}
		}
		dq.push_back(mp(i, a));
		printf("%d ", dq.front().second);
	}


	return 0;
}