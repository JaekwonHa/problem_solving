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

int N, S;
pair<int,int> p[300010];
int DP[300010];
int h[300010];

int f(int pos) {

	if (pos == N) return 0;

	int& ret = DP[pos];
	if (ret != -1) return ret;

	ret = f(pos + 1);
	int next = lower_bound(h, h + N, p[pos].first + S) - h;
	ret = max(ret, f(next) + p[pos].second);

	return ret;
}


int main() {

	scanf("%d%d", &N, &S);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		p[i] = mp(a, b);
		h[i] = a;
	}
	sort(p, p + N);
	sort(h, h + N);

	memset(DP, -1, sizeof(DP));

	printf("%d\n", f(0));

	return 0;
}