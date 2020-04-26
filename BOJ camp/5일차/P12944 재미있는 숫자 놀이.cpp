#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

#define PLUS 0
#define MINUS 1

int N;

int GCD(int a, int b) {
	int t1, t2;
	t1 = min(a, b);
	t2 = max(a, b);
	if (t2%t1 == 0) return t1;
	return GCD(t1, t2 % t1);
}

int LCM(int a, int b) {
	int t1, t2;
	t1 = min(a, b);
	t2 = max(a, b);
	return (t1*t2)/GCD(t1, t2);
}

int go(vector<int> v, int type) {
	if (v.size() == 0) return 0;
	if (v.size() == 1) {
		if (type == PLUS) return N / v[0];
		return -(N / v[0]);
	}
	int ret = 0;
	ret += (N / v[0]);
	for (int i = 1; i < v.size(); i++) {
		ret += (N / v[i]);
		int temp;
		vector<int> tv;
		for (int j = 0; j < i; j++) {
			temp = LCM(v[i], v[j]);
			tv.push_back(temp);
		}
		if (type == PLUS) ret = ret + go(tv, MINUS);
		else ret = ret - go(tv, PLUS);
	}
	if (type == PLUS) return ret;
	return -ret;
}

int main() {

	vector<int> v;
	int K,a;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &a);
		v.push_back(a);
	}

	int ans = 0;

	ans += go(v, PLUS);

	printf("%d\n", ans);

	return 0;
}

