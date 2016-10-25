#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100005
typedef pair<int, int> pii;
typedef vector<pii> NODE;
typedef vector<NODE> TREE;

int T, N, Q;
int X[MAXN * 3], XC, Y[MAXN * 3], YC;
int ST;
bool out[MAXN];

struct {
	int x1, y1, x2, y2, v;
} A[MAXN];

struct {
	int x, t;
} L[MAXN];

TREE xtree, ytree;

void write(TREE &tree, int l, int r, int v, int idx)
{
	for (; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			tree[l].push_back(pii(v, idx));
			l++;
		}
		if (!(r & 1)) {
			tree[r].push_back(pii(v, idx));
			r--;
		}
	}
}

int get_val(TREE &tree, int n)
{
	int ret = 0, t = n;
	for (; n; n >>= 1) {
		while (!tree[n].empty()) {
			if (!out[tree[n].back().second] && ret < tree[n].back().first)
				ret = tree[n].back().first;
			out[tree[n].back().second] = 1;
			tree[n].pop_back();
		}
	}
	return ret;
}

int main()
{
	int i;
	for (scanf("%d", &T); T--;) {
		scanf("%*d%d%d", &N, &Q); XC = YC = 0;
		for (i = 1; i <= N; i++) {
			scanf("%d%d%d%d%d", &A[i].x1, &A[i].y1, &A[i].x2, &A[i].y2, &A[i].v);
			X[++XC] = A[i].x1; X[++XC] = A[i].x2;
			Y[++YC] = A[i].y1; Y[++YC] = A[i].y2;
			out[i] = 0;
		}
		for (i = 1; i <= Q; i++) {
			scanf("%d%d", &L[i].x, &L[i].t);
			if (L[i].t) X[++XC] = L[i].x;
			else Y[++YC] = L[i].x;
		}
		sort(X + 1, X + XC + 1);
		sort(Y + 1, Y + YC + 1);
		XC = unique(X + 1, X + XC + 1) - X - 1;
		YC = unique(Y + 1, Y + YC + 1) - Y - 1;
		for (i = 1; i <= N; i++) {

			A[i].x1 = lower_bound(X + 1, X + XC + 1, A[i].x1) - X;
			A[i].x2 = lower_bound(X + 1, X + XC + 1, A[i].x2) - X;
			A[i].y1 = lower_bound(Y + 1, Y + YC + 1, A[i].y1) - Y;
			A[i].y2 = lower_bound(Y + 1, Y + YC + 1, A[i].y2) - Y;
			if (A[i].x1 > A[i].x2) swap(A[i].x1, A[i].x2);
			if (A[i].y1 > A[i].y2) swap(A[i].y1, A[i].y2);
		}
		for (ST = 2; ST<XC || ST<YC; ST <<= 1);
		xtree = TREE(ST << 1);
		ytree = TREE(ST << 1);
		ST--;
		for (i = 1; i <= N; i++) {
			write(xtree, ST + A[i].x1, ST + A[i].x2, A[i].v, i);
			write(ytree, ST + A[i].y1, ST + A[i].y2, A[i].v, i);
		}
		for (i = 1; i <= Q; i++) {
			if (L[i].t) L[i].x = lower_bound(X + 1, X + XC + 1, L[i].x) - X;
			else L[i].x = lower_bound(Y + 1, Y + YC + 1, L[i].x) - Y;
			if (L[i].t) { // ¼öÁ÷
				printf("%d\n", get_val(xtree, ST + L[i].x));
			}
			else {
				printf("%d\n", get_val(ytree, ST + L[i].x));
			}
		}
	}
}