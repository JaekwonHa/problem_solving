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
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;


int main() {

	int n, m;
	char ch[21];
	map<string, int> M;
	map<string, int> M2;
	
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%s", ch);
		M[ch]++;
	}
	for (int i = 0; i < m; i++) {
		scanf("%s", ch);
		if (M.count(ch) > 0) M2[ch]++;
	}
	printf("%d\n", M2.size());
	for (auto a : M2) {
		printf("%s\n", a.first.c_str());
	}

	return 0;
}