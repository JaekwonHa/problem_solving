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

int m[1001][1001];
int N, M, X;

int main() {

	scanf("%d %d %d", &N, &M, &X);

	for (int i = 0; i <= N; i++) {
		fill(m[i], m[i] + N + 1, INF);
	}

	for (int i = 0; i < M; i++) {
		int start, dest, cost;
		scanf("%d %d %d", &start, &dest, &cost);
		m[start][dest] = cost;
		//m[dest][start] = cost;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (m[i][k] + m[k][j] < m[i][j]) {
					m[i][j] = m[i][k] + m[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		ans = max(ans, m[i][X] + m[X][i]);
	}

	printf("%d\n", ans);

	return 0;
}