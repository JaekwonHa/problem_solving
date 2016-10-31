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
	int src, dest, box;
	P() {}
	P(int a, int b, int c) : src(a), dest(b), box(c) {}
};
int sum[2010];


int main() {

	int N, C, M;
	scanf("%d %d %d", &N, &C, &M);

	vector<P> arr(M);

	int a, b, c;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[i] = P(a, b, c);
	}

	sort(arr.begin(), arr.end(), [](const P &a, const P &b) {
		if (a.dest == b.dest) {
			return a.src < b.src;
		}
		else {
			return a.dest < b.dest;
		}
	});

	int cur = 0;
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int m = 0;
		for (int j = arr[i].src; j < arr[i].dest; j++) {
			m = max(m, sum[j]);
		}
		m = min(C - m, arr[i].box);
		for (int j = arr[i].src; j < arr[i].dest; j++) {
			sum[j] += m;
		}
		ans += m;
	}

	printf("%d\n", ans);

	return 0;
}