#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>

typedef std::pair<int, int> Present;

int N, D;
int P[100010], V[100010];
long long ans;

void solveSlidingWindow() {
	std::vector<Present> v;
	for (int i = 0; i < N; i++) v.push_back(std::make_pair(P[i], V[i]));


	sort(v.begin(), v.end(), [](Present a, Present b) {
		return a.first <= b.first;
	});

	int s, e;
	long long sum = 0, ans = 0;
	for (e = 0; e < N && v[e].first - v[0].first < D; e++) sum += v[e].second;

	ans = sum;
	for (int i = 1; i < N; i++) {
		sum -= v[i - 1].second;
		while (e<N && v[e].first - v[i].first < D) {
			sum += v[e].second;
			e++;
		}
		ans = std::max(ans, sum);
	}
}

void solveBinarySearch() {
	std::vector<Present> v;
	for (int i = 0; i < N; i++) v.push_back(std::make_pair(P[i], V[i]));

	sort(v.begin(), v.end(), [](Present a, Present b) {
		return a.first <= b.first;
	});

	long long acc[100010];
	acc[0] = v[0].second;
	for (int i = 1; i < N; i++) acc[i] = acc[i - 1] + v[i].second;

	int lb = 0, ub = N,m;
	long long sum;
	for (int i = 0; i < N; i++) {
		lb = i, ub = N-1;
		while (lb <= ub) {
			m = (lb + ub) / 2;
			if (v[m].first - v[i].first < D) lb = m+1;
			else ub = m-1;
		}
		sum = acc[ub] - acc[i] + v[i].second;
		ans = std::max(ans, sum);
	}
}

int main() {
	int a, b;
	scanf("%d %d", &N, &D);
	for (int i = 0; i < N; i++) scanf("%d %d", &P[i], &V[i]);

	solveBinarySearch();
	
	printf("%lld\n", ans);

	return 0;
}