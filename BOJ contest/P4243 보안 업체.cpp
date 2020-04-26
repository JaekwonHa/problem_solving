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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

ll DP[110][110][3];
ll dis[110];
int N;

ll f(int left, int right, int pos, int cnt) {
	if (left == 1 && right == N) return 0;
	if (left<1 || right > N) return INF;

	ll &ret = DP[left][right][pos];
	if (ret != -1) return ret;

	ret = INF;

	ll cost;
	if (pos == 0) {
		if (right < N) {
			cost = dis[right + 1] - dis[left];
			ret = min(ret, cost*cnt + f(left, right + 1, 1, cnt - 1));
		}
		if (left > 1) {
			cost = dis[left] - dis[left - 1];
			ret = min(ret, cost*cnt + f(left - 1, right, 0, cnt - 1));
		}
	}
	else {
		if (right < N) {
			cost = dis[right + 1] - dis[right];
			ret = min(ret, cost*cnt + f(left, right + 1, 1, cnt - 1));
		}
		if (left > 1) {
			cost = dis[right] - dis[left - 1];
			ret = min(ret, cost*cnt + f(left - 1, right, 0, cnt - 1));
		}
	}

	return ret;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {

		int a, b;
		memset(DP, -1, sizeof(DP));
		memset(dis, 0, sizeof(dis));

		scanf("%d", &N);
		scanf("%d", &a);
		scanf("%lld", &dis[2]);
		for (int i = 3; i <= N; i++) {
			scanf("%d", &b);
			dis[i] = dis[i - 1] + b;
		}
		dis[N + 1] = dis[N];
		printf("%lld\n", f(a, a, 0, N - 1));

	}

	return 0;
}