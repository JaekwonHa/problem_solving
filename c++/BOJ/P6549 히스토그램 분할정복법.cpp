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
using namespace std;

#define INF 987654321
#define mod 1000000007
#define MAXN 400040
typedef long long ll;

int seg[MAXN];
int n, idx = 1;
vector<int> v;

// 햇갈리지 말자. start end 는 내가 보고있는 범위, lo, hi는 트리의 전체 구간,  node는 node번호.   그래서 처음에 init할때 1번노드부터 init을 한다.
// 2*,   2* +1 하면서 왼쪽 오른쪽을 init하고 결과를 둘중에 비교해서 자기에게 넣는다.

void init(int node, int start, int end) {
	if (end < start) {
		seg[node] = INF;
	} else if (start == end) {
		seg[node] = start;
	}
	else {
		int mid = (start + end) / 2;
		init(node * 2, start, mid);
		init(node * 2 + 1, mid + 1, end);
		if (v[seg[node * 2]] < v[seg[node * 2 + 1]]) {
			seg[node] = seg[node * 2];
		}
		else {
			seg[node] = seg[node * 2 + 1];
		}
	}
}

int query(int start, int end, int node, int lo, int hi) {
	if (start > hi || end < lo) {
		return -1;
	}
	if (lo <= start && end <= hi) {
		return seg[node];
	}
	int mid = (start + end) / 2;
	int m1 = query(start, mid, node * 2, lo, hi);
	int m2 = query(mid + 1, end, node * 2 + 1, lo, hi);
	
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else if (v[m1] <= v[m2]) return m1;
	else return m2;
}

ll f(int start, int end) {

	int m = query(0, n-1, 1, start, end);
	ll ret;

	ret = (ll)v[m] * (ll)(end - start + 1);
	if (start <= m - 1) {
		ret = max(ret, f(start, m - 1));
	}
	if (m + 1 <= end) {
		ret = max(ret, f(m + 1, end));
	}
	return ret;
}

int main() {

	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		v.clear();
		v.resize(n);
		int base = 1;
		while (base < n) base *= 2;
		for (int i = 0; i < n; i++) scanf("%d", &v[i]);
		init(1, 0, n - 1);
		printf("%lld\n", f(0, n - 1));
	}

	return 0;
}