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

#define INF 987654321
#define mod 1000000007
#define mt make_tuple
#define mp make_pair
typedef long long ll;

int n, L;
int arr[5000001];

void makeTree(int *tree, int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
	}
	else {
		makeTree(tree, start, (start + end) / 2, node * 2);
		makeTree(tree, (start + end) / 2 + 1, end, node * 2 + 1);
		if (tree[node * 2] < tree[node * 2 + 1]) {
			tree[node] = tree[node * 2];
		}
		else {
			tree[node] = tree[node * 2 + 1];
		}
	}
}

int query(int *tree, int start, int end, int node, int lo, int hi) {
	if (hi < start || end < lo) {
		return INF;
	}
	if (lo <= start && end <= hi) {
		return tree[node];
	}

	int m1 = query(tree, start, (start + end) / 2, node * 2, lo, hi);
	int m2 = query(tree, (start + end) / 2 + 1, end, node * 2 + 1, lo, hi);

	if (m1 == INF) return m2;
	if (m2 == INF) return m1;

	return min(m1, m2);
}

int main() {

	scanf("%d %d", &n, &L);
	
	int base = 1;
	while (base < n) base *= 2;
	
	int *tree = new int[base * 2];
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	makeTree(tree,0,n-1,1);

	for (int i = 0; i < n; i++) {
		printf("%d ", query(tree, 0, n - 1, 1, max(0, i - L+1), i));
	}


	return 0;
}