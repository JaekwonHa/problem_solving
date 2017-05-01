#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1000000
#define ll long long

int N,M,K,base;
ll arr[MAXN];

typedef struct Tree {
	ll value, lazy;
} Tree;
Tree tree[3*MAXN];

ll init(int node, int start, int end) {
	if(start==end)
		return tree[node].value = arr[start];
	else
		return tree[node].value = init(node*2,start, (start+end)/2) + init(node*2+1, (start+end)/2+1, end);
}

void update_range(int node, int start, int end, int i, int j, ll diff) {
	if(tree[node].lazy != 0) {
		tree[node].value += (end-start+1)*tree[node].lazy;
		if(start!=end) {
			tree[node*2].lazy += tree[node].lazy;
			tree[node*2+1].lazy += tree[node].lazy;
		}
		tree[node].lazy=0;
	}
	if(j<start || i>end) return;
	if(i<=start && end<=j) {
		tree[node].value += (end-start+1)*diff;
		if(start != end) {
			tree[node*2].lazy += diff;
			tree[node*2+1].lazy += diff;
		}
		return;
	}
	update_range(node*2, start, (start+end)/2, i, j, diff);
	update_range(node*2+1, (start+end)/2+1, end, i, j, diff);

	tree[node].value = tree[node*2].value + tree[node*2+1].value;
}

ll sum(int node, int start, int end, int i, int j) {
	if(tree[node].lazy !=0 ) {
		tree[node].value += (end-start+1)*tree[node].lazy;
		if(start != end) {
			tree[node*2].lazy += tree[node].lazy;
			tree[node*2+1].lazy += tree[node].lazy;
		}
		tree[node].lazy=0;
	}
	if(j<start || i>end) return 0;
	if(i<=start && end<=j) return tree[node].value;
	return sum(node*2, start, (start+end)/2, i, j) + sum(node*2+1, (start+end)/2+1, end, i, j);
}

int main() {

	scanf("%d %d %d", &N, &M, &K);
	for(int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
	}
	init(1,1,N);
	for(int i=0; i<M+K; i++) {
		int a,b,c,d;
		scanf("%d", &a);
		if(a==1) {
			scanf("%d %d %d", &b, &c, &d);
			update_range(1,1,N,b,c,d);
		} else {
			scanf("%d %d", &b, &c);
			printf("%lld\n", sum(1,1,N,b,c));
		}
	}

	return 0;
}