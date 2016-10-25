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


#define INF 9876543210
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int N, M;
int cnt[1001];
vector<int> v[1001];

vector<int> ans;

void TP() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		ans.push_back(cur);

		for (int i : v[cur]) {
			cnt[i]--;
			if (cnt[i] == 0) {
				q.push(i);
			}
		}

	}

}

int main() {

	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a, b, prev = 0;
		scanf("%d", &a);
		for (int i = 0; i < a; i++) {
			scanf("%d", &b);
			
			if (prev != 0) {
				cnt[b]++;
				v[prev].push_back(b);
			}
			prev = b;
		}
	}

	TP();

	if (ans.size() == N) {
		for (int i : ans) {
			printf("%d\n", i);
		}
	}
	else {
		printf("0\n");
	}

	return 0;
}