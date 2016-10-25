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
#define mt make_tuple
typedef long long ll;


map<int, int> m;
vector<int> v;


int main() {

	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	queue<tuple<int, int, int>> q;
	q.push(mt(0, 0, C));
	while (!q.empty()) {
		int a, b, c;
		tie(a, b, c) = q.front();
		q.pop();
		if (a == 0) v.push_back(c);

		int t1, t2, t3;
		// C->A
		t1 = min(A, a + c);
		t2 = b;
		t3 = a + c - t1;
		if (m.count(t1 * 100000 + t2 * 1000 + t3) == 0) q.push(mt(t1, t2, t3)), m[t1 * 100000 + t2 * 1000 + t3]++;
		
		// C->B
		t1 = a;
		t2 = min(B, b + c);
		t3 = b + c - t2;
		if (m.count(t1 * 100000 + t2 * 1000 + t3) == 0) q.push(mt(t1, t2, t3)), m[t1 * 100000 + t2 * 1000 + t3]++;
		// A->B
		t2 = min(B, a + b);
		t1 = a + b - t2;
		t3 = c;
		if (m.count(t1 * 100000 + t2 * 1000 + t3) == 0) q.push(mt(t1, t2, t3)), m[t1 * 100000 + t2 * 1000 + t3]++;
		// A->C
		t3 = min(C, a + c);
		t1 = a + c - t3;
		t2 = b;
		if (m.count(t1 * 100000 + t2 * 1000 + t3) == 0) q.push(mt(t1, t2, t3)), m[t1 * 100000 + t2 * 1000 + t3]++;
		// B->A
		t1 = min(A, a + b);
		t2 = a + b - t1;
		t3 = c;
		if (m.count(t1 * 100000 + t2 * 1000 + t3) == 0) q.push(mt(t1, t2, t3)), m[t1 * 100000 + t2 * 1000 + t3]++;
		// B->C
		t1 = a;
		t2 = min(B, b + c);
		t3 = b + c - t2;
		if (m.count(t1 * 100000 + t2 * 1000 + t3) == 0) q.push(mt(t1, t2, t3)), m[t1 * 100000 + t2 * 1000 + t3]++;
	}

	sort(v.begin(), v.end());
	printf("%d ", v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] == v[i - 1]) continue;
		printf("%d ", v[i]);
	}

	return 0;
}