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

int n;
int cnt[500010];
int d[500010];
int m, p;
int idx[500010];

#define PERSON 0
#define MAFIA 1

void f(int now, int type) {
	if (idx[now] == MAFIA) return;
	idx[now] = 1;
	cnt[d[now]]--;
	m += type;
	if (cnt[d[now]] == 0 || type == MAFIA) {
		f(d[now], !type);
	}
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		d[i] = a;
		cnt[a]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			f(i, MAFIA);
		}
	}
	for (int i = 1; i <= n; i++) {
		f(i, PERSON);
	}
	printf("%d\n", m);

	return 0;
}