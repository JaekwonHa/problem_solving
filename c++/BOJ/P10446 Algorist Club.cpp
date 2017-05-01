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


int main() {

	int T;
	scanf("%d", &T);

	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<int> v(n + 1, 0);
		vector<pair<int, int>> edges;
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v[a]++;
			v[b]++;
			edges.push_back(mp(a, b));
		}
		int K = 0, kCnt = 0;
		for (int i : v) {
			if (kCnt < i) {
				kCnt = i;
			}
		}
		int i = 0;
		for (auto a : edges) {
			printf("%d %d %d\n", a.first, a.second, i % (kCnt + 1) + 1);
			i++;
		}
	}

	return 0;
}