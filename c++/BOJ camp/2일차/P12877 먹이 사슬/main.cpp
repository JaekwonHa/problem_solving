#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Union {
	vector<int> p, r;
	// 초기에는 모두가 조상이 자기 자신
	Union(int n) : p(n + 1), r(n + 1, 1) {
		for (int i = 0; i < n + 1; i++) {
			p[i] = i;
		}
	}
	// 조상을 찾아서 리턴
	int find(int u) {
		if (p[u] == u) return u;
		return p[u] = find(p[u]);
	}
	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) {
			return;
		}
		if (r[u] == r[v]) {
			swap(u, v);
		}
		p[u] = v;
		if (r[u] == r[v]) {
			++r[v];
		}
	}
	bool isSameSet(int u, int v) {
		return find(u) == find(v);
	}
};

int N, K, ans;

int main() {
	scanf("%d %d", &N, &K);
	Union uni(N * 3);
	int t, x, y;
	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &t, &x, &y);
		if (1 <= x && x <= N && 1 <= y && y <= N) {
			if (t == 1) {
				if (uni.isSameSet(x, y + N) || uni.isSameSet(x, y + 2 * N)) {
					ans++;
				}
				else {
					uni.merge(x, y);
					uni.merge(x + N, y + N);
					uni.merge(x + 2 * N, y + 2 * N);
				}
			}
			else {
				if (uni.isSameSet(x, y) || uni.isSameSet(y + 2 * N, x)) {
					ans++;
				}
				else {
					uni.merge(x, y + N);
					uni.merge(x + N, y + 2 * N);
					uni.merge(x + 2 * N, y);
				}
			}
		}
		else {
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}