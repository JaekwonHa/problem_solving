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

bool mark[300010];
queue<int> e[300010];

int main() {

	int n, q, time=1;
	int type, x, ans = 0;
	queue<pair<int, int>> qu;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d %d", &type, &x);
		
		if (type == 1) {
			qu.push(mp(time, x));
			ans++;
			e[x].push(time);
			mark[time] = true;
			time++;
		}
		else if (type == 2) {
			ans -= e[x].size();
			while (!e[x].empty()) {
				mark[e[x].front()] = false;
				e[x].pop();
			}
		}
		else {
			x = max(0, x - qu.front().first + 1);
			while (!qu.empty() && x) {
				
				if (mark[qu.front().first] == true) {
					ans--;
					e[qu.front().second].pop();
				}
				x--;
				qu.pop();
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}