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

// ������ ll �̻��� ��� INF�� 98765432100000 �������� ũ�� �ؾ���
// �Է¹޴� ���� 10^9 �̰� ���� ���� �װ͵��� ���ϴ� �����̶�� ���� ll �ϼ� �ִ�

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
	
	// ���� ���� �߶�� �Ѵٸ� �ڽĳ���� ��+1 �� �߶���ϴ� ���� ������ �����Ѵ�
	// ���� ���� �ڸ��� �ʾƵ� �ȴٸ� �ڽĵ��� �߶�� �ϴ� ���� ���� �����Ѵ�

	// �ڽ��Ǽ�, �ڽĵ��� �߶�� �ϴ� �͵��� ��
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