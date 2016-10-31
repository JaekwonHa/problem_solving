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
typedef long long ll;

int L, C;
vector<char> v;
vector<char*> ans;
char *a;

void dfs(int pos, int len) {
	if (len == L) {
		int cnt = 0;
		for (int i = 0; i < len; i++) {
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') cnt++;
		}
		if (cnt >= 1 && len - cnt >= 2) {
			a[len] = '\0';
			printf("%s\n", a);
		}
		return;
	}

	for (int i = pos; i < C - L + len + 1; i++) {
		a[len] = v[i];
		dfs(i + 1, len + 1);
	}
}

int main() {

	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		char c;
		scanf(" %c", &c);
		v.push_back(c);
	}
	sort(v.begin(), v.end());

	a = new char[L+1];
	
	for (int i = 0; i < C - L + 1; i++) {
		a[0] = v[i];
		dfs(i + 1, 1);
	}

	return 0;
}