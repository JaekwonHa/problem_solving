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
#include <sstream>
using namespace std;

// 정답이 ll 이상일 경우 INF를 98765432100000 정도까지 크게 해야함
// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다
// priority_queue 는 기본적으로 내림차순 정렬이다. 오름차순으로 하고 싶다면 priority_queue<int, vector<int>, greater<int>>
// queue에서 pop하기 전에는 반드시 empty인 경우를 체크하고 예외처리 해줘라


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

bool check[1000006];

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int k;
		ll n;
		char c;
		scanf("%d", &k);

		memset(check, 0, sizeof(check));
		priority_queue<pair<ll, int>> mx, mn;

		for (int i = 0; i < k; i++) {
			scanf("\n%c %lld", &c, &n);
			if (c == 'I') {
				mx.push(mp(n, i));
				mn.push(mp(-n, i));
			}
			else {
				while (!mx.empty() && check[mx.top().second]) mx.pop();
				while (!mn.empty() && check[mn.top().second]) mn.pop();

				if (n == 1) {
					if (!mx.empty()) {
						check[mx.top().second] = true;
						mx.pop();
					}
				}
				else {
					if (!mn.empty()) {
						check[mn.top().second] = true;
						mn.pop();
					}
				}

			}
			

		}
		while (!mx.empty() && check[mx.top().second]) mx.pop();
		while (!mn.empty() && check[mn.top().second]) mn.pop();
		if (mx.empty() || mn.empty()) {
			printf("EMPTY\n");
		}
		else {
			printf("%lld %lld\n", mx.top().first, -mn.top().first);
		}
	}

	return 0;
}