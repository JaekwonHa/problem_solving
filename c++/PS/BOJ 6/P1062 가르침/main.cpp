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

int N, K;
char ch[100]['z' + 10];
char candi['z' + 10];
vector<char> v;
char sel['z' + 10];
vector<char> cc;

int cal() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool ok = true;
		for (int j = 'a'; j <= 'z'; j++) {
			if (ch[i][j] == 1 && sel[j]==0) {
				ok = false;
				break;
			}
		}
		if (ok) ans++;
	}
	return ans;
}

int f(int pos, int k) {
	if (pos>=v.size() || k == 0) {
		return cal();
	}

	int ans = 0;
	for (int i = pos; i < v.size(); i++) {
		cc.push_back(v[i]);
		sel[v[i]] = 1;
		ans = max(ans, f(i + 1, k-1));
		sel[v[i]] = 0;
		cc.pop_back();
	}
	return ans;
}

int main() {

	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		char a[20];
		scanf("%s", a);
		int len = strlen(a);
		for (int j = 0; j < len; j++) {
			if (a[j] == 'a' || a[j] == 'n' || a[j] == 't' || a[j] == 'i' || a[j] == 'c') continue;
			ch[i][a[j]] = 1;
			if (candi[a[j]] == 0) {
				candi[a[j]] = 1;
				v.push_back(a[j]);
			}
		}
	}
	int ans = 0;
	if (K<=5) {
		if (K == 5) {
			ans = cal();
		}
	}
	else if (K - 5 >= v.size()) {
		ans = N;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			cc.push_back(v[i]);
			sel[v[i]] = 1;
			ans = max(ans, f(i + 1, K - 6));
			sel[v[i]] = 0;
			cc.pop_back();
		}
	}
	printf("%d\n", ans);

	return 0;
}