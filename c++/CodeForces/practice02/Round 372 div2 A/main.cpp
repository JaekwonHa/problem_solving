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
// 입력받는 값이 10^9 이고 답이 뭔가 그것들을 더하는 연산이라면 답은 ll 일수 있다
// priority_queue 는 기본적으로 내림차순 정렬이다. 오름차순으로 하고 싶다면 priority_queue<int, vector<int>, greater<int>>
// queue에서 pop하기 전에는 반드시 empty인 경우를 체크하고 예외처리 해줘라


#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;


int main() {

	ll l1, r1, l2, r2, k;
	scanf("%I64d%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2, &k);

	ll ans = 0;
	if (l1 <= l2) {
		if (r2 <= r1) {
			ans = r2 - l2 + 1;
			if (l2 <= k && k <= r2) {
				ans--;
			}
		}
		else if (r1 <= r2) {
			ans = r1 - l2 + 1;
			if (l2 <= k && k <= r1) {
				ans--;
			}
		}
	}
	else if(l2 <= r1) {
		if (r2 < l1) {
			ans = 0;
		}
		else if (r2 <= r1) {
			ans = r2 - l1 + 1;
			if (l1 <= k && k <= r2) {
				ans--;
			}
		}
		else {
			ans = r1 - l1 + 1;
			if (l1 <= k && k <= r1) {
				ans--;
			}
		}
	}
	else {
		ans = 0;
	}
	ans = max(ans, 0ll);
	printf("%I64d\n", ans);

	return 0;
}