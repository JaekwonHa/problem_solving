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
int N, nmin, nmax;
int P[201];
int main() {

	while (1) {
		scanf("%d%d%d", &N, &nmin, &nmax);
		if (N == 0 && nmin == 0 && nmax == 0) break;

		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
		}

		int gap = 0;
		int ans = 1;
		for (int i = 1; i<nmin; i++) {
			ans++;
			//gap = max(gap, P[i-1] - P[i]);
		}
		gap = P[nmin - 1] - P[nmin];
		for (int i = nmin; i<nmax; i++) {
			if (gap <= P[i] - P[i+1]) {
				ans = i + 1;
				gap = P[i] - P[i+1];
			}
		}
		printf("%d\n", ans);
	}


	return 0;
}