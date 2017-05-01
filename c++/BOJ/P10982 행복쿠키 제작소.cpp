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

#define MAX 100000

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {

		int N;
		
		vector<int> prev(MAX, INF);
		int a, b;
		scanf("%d", &N);
		scanf("%d %d", &a, &b);
		prev[a] = 0;
		prev[0] = b;

		for (int i = 1; i < N; i++) {
			scanf("%d %d", &a, &b);

			vector<int> DP(MAX, INF);

			for (int i = MAX - 1; i >= 0; i--) {
				if (prev[i] != INF) {
					DP[i] = min(DP[i], prev[i] + b);
				}
			}

			for (int i = MAX - 1; i >= 0; i--) {
				if (prev[i] != INF) {
					DP[i + a] = min(DP[i + a], prev[i]);
				}
			}

			for (int i = MAX - 1; i >= 0; i--) {
				prev[i] = DP[i];
			}
		}

		int ans = INF;
		for (int i = MAX - 1; i >= 0; i--) {
			ans = min(ans, max(prev[i], i));
		}
		printf("%d\n", ans);
	}

	return 0;
}