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

struct P {
	int a, b, c, idx, price;
	P() {}
	P(int x, int y, int z, int i) : a(x), b(y), c(z), idx(i) {}
	bool operator==(const P& X) {
		if (a == X.a && b == X.b && c == X.c) return true;
		return false;
	}
};


int main() {

	int N, K;
	scanf("%d %d", &N, &K);

	vector<P> v(N+1);

	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		v[i] = P(b, c, d, a);
	}
	v[N] = P(INF, INF, INF, -1);
	sort(v.begin(), v.end(), [](P a, P b) {
		if (a.a != b.a) return a.a > b.a;
		else if (a.b != b.b) return a.b > b.b;
		else return a.c > b.c;
	});

	int ans = 0;
	int idx = 1;
	for (int i = 1; i <= N; i++, idx++) {
		if (v[i - 1] == v[i]) {
			v[i].price = v[i - 1].price;
		}
		else {
			v[i].price = i;
		}
	}
	for (int i = 1; i <= N; i++, idx++) {
		if (v[i].idx == K) {
			ans = v[i].price;
			break;
		}
	}
	printf("%d", ans);

	return 0;
}