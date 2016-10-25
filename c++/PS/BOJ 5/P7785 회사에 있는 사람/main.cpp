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

	map<string, int> m;
	int n;
	scanf("%d", &n);
	char ch1[101], ch2[6];
	for (int i = 0; i < n; i++) {
		scanf("%s %s", ch1, ch2);
		m[ch1]++;
	}
	auto a = m.end();
	a--;
	for (; a != m.begin(); a--) {
		if ((*a).second % 2 == 1) printf("%s\n", (*a).first.c_str());
	}
	if ((*a).second % 2 == 1) printf("%s\n", (*a).first.c_str());

	return 0;
}