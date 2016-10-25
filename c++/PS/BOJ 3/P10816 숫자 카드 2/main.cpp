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
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

int v[500001];

int main() {

	map<int, int> m;
	int n, M, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		m[a]++;
	}
	int size = 0;
	//for (auto a : m) v[size++] = a.first;
	size--;

	scanf("%d", &M);


	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		/*
		int lb = 0, ub = size, md;
		while (lb <= ub) {
			md = (lb + ub) / 2;
			if (v[md] > a) ub = max(0,md - 1);
			if (v[md] < a) lb = min(n-1,md + 1);
			if (v[md] == a) break;
		}*/
		if(m.count(a)>0) printf("%d ", m[a]);
		else printf("0 ");
	}

	return 0;
}