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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n;
int v[100001];
vector<pair<int,int>> edge[100001];
bool visit[100001];

pair<int, int> dfs(int pos, ll w) {
	if (pos == 0 || visit[pos] == true) return mp(0, 0);
	
	// 현재 것을 잘라야 한다면 자식노드의 수+1 을 잘라야하는 것의 개수로 리턴한다
	// 현재 것을 자르지 않아도 된다면 자식들중 잘라야 하는 것의 수를 리턴한다

	// 자식의수, 자식들중 잘라야 하는 것들의 수
	if (w < 0) w = 0;
	
	visit[pos] = true;

	int ans1 = 0, ans2 = 0;
	for (auto a : edge[pos]) {
		int t1, t2;
		tie(t1, t2) = dfs(a.first, w + a.second);
		ans1 += t1;
		ans2 += t2;
	}
	if (w > v[pos]) return mp(ans2+1, ans2+1);
	else return mp(ans1, ans2+1);
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	int p, c;
	for (int i = 2; i <= n; i++) {
		scanf("%d %d", &p, &c);
		edge[i].push_back(mp(p, c));
		edge[p].push_back(mp(i, c));
	}

	int ans1, ans2;
	tie(ans1,ans2) = dfs(1, 0);

	printf("%d\n", ans1);

	return 0;
}