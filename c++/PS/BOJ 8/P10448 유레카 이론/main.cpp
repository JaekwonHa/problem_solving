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

bool dfs(int n, int a, int cnt) {
	if (a == 0 && cnt == 3) return true;
	if (cnt > 3 || n == 0 || a <= 0) return false;

	bool ok = dfs(n - 1, a, cnt);
	ok |= dfs(n - 1, a - (n*(n + 1) / 2), cnt + 1);
	ok |= dfs(n - 1, a - (n*(n + 1)), cnt + 2);
	ok |= dfs(n - 1, a - ((n*(n + 1) / 2) * 3), cnt + 3);

	return ok;
}

int main() {

	int T;
	scanf("%d", &T);
	while (T--) {
		int a;
		scanf("%d", &a);

		int n = 1;
		while (n*(n+1)/2 < a) {
			n++;
		}

		bool ok = dfs(n, a, 0);

		ok ? printf("1\n") : printf("0\n");
	}

	return 0;
}