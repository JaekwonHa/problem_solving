#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
struct data {
	int max, min;
} d_tmp;
data index_tree[270000];
int N_i, N, M;

void indextree_input(int chk, int num) {
	index_tree[chk].max = index_tree[chk].min = num;
	while (chk > 0) {
		chk = chk >> 1;
		index_tree[chk].min = std::min(index_tree[chk*2].min, index_tree[chk*2 + 1].min);
		index_tree[chk].max = std::max(index_tree[chk*2].max, index_tree[chk*2 + 1].max);
	}
	return;
}
data indextree_getminmax(int A, int B, data d) {
	if (A == B) {
		d.min = std::min(d.min, index_tree[A].min);
		d.max = std::max(d.max, index_tree[A].max);
		return d;
	}
	if (A % 2 == 1) {
		d.min = std::min(d.min, index_tree[A].min);
		d.max = std::max(d.max, index_tree[A].max);
		A++;
	}
	if (A == B) {
		d.min = std::min(d.min, index_tree[A].min);
		d.max = std::max(d.max, index_tree[A].max);
		return d;
	}
	if (B % 2 == 0) {
		d.min = std::min(d.min, index_tree[B].min);
		d.max = std::max(d.max, index_tree[B].max);
		B--;
	}
	return indextree_getminmax(A>>1, B>>1, d);
}
int main() {

	scanf("%d %d", &N, &M);
	N_i = 1;
	int i, t;
	while (N_i < N) N_i *= 2;
	for (i = 1; i <= N_i+N; i++) index_tree[i].min = 2000000000;
	for (i = 0; i < N; i++) {
		scanf("%d", &t);
		indextree_input(N_i + i, t);
	}

	int a, b;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &a, &b);
		d_tmp.max = 0, d_tmp.min = 2000000000;
		d_tmp = indextree_getminmax(N_i+a-1, N_i + b-1, d_tmp);
		printf("%d %d\n", d_tmp.min, d_tmp.max);
	}

	return 0;
}