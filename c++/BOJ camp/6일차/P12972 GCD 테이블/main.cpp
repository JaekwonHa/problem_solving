#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int N;
int arr[250001];

int gcd(int a, int b) {
	int r = a%b;
	if (r == 0) return b;
	return gcd(b, r);
}

void solveQueue() {
	scanf("%d", &N);
	for (int i = 0; i < N*N; i++) scanf("%d", arr + i);

	sort(arr, arr + N*N);
	priority_queue<int> pq;
	int ans[500], cov = 0;
	for (int i = N*N - 1; i >= 0 && cov < N; i--) {
		if (!pq.empty()) {
			if (arr[i] == pq.top()) {
				pq.pop();
				continue;
			}
		}
		printf("%d ", arr[i]);
		for (int j = 0; j < cov; j++) {
			pq.push(gcd(ans[j], arr[i]));
			pq.push(gcd(ans[j], arr[i]));
		}
		ans[cov++] = arr[i];
	}
}

void solveMap() {
	scanf("%d", &N);
	for (int i = 0; i < N*N; i++) scanf("%d", arr + i);

	sort(arr, arr + N*N);
	map<int, int> d;
	int ans[500],cov=0;
	for (int i = N*N - 1; i >= 0; i--) {
		if (d[arr[i]]>0) {
			d[arr[i]]--;
			continue;
		}
		for (int j = 0; j < cov; j++) {
			int t = gcd(ans[j], arr[i]);
			d[t]++, d[t]++;
		}
		ans[cov++] = arr[i];
	}
	for (int i = 0; i < cov; i++) {
		printf("%d ", ans[i]);
	}
}

void solveMultiSet() {

	multiset<int> ms;

	scanf("%d", &N);
	for (int i = 0; i < N*N; i++) { scanf("%d", arr + i); ms.insert(arr[i]); }

	int ans[500], cov = 0;
	for (int i = 0; i < N; i++) {
		auto a = ms.end();
		a--;
		ans[i] = *a;
		ms.erase(a);
		for (int j = 0; j < i; j++) {
			int t = gcd(ans[i], ans[j]);
			auto aa = ms.lower_bound(t);
			ms.erase(aa);
			aa = ms.lower_bound(t);
			ms.erase(aa);
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", ans[i]);
	}
}

int main() {

	//solveQueue();
	//solveMap();
	solveMultiSet();

	

	return 0;
}

