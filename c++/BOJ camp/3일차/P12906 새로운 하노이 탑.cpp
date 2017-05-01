#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main() {

	vector<string> s(3);
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		if (a > 0) cin >> s[i];
	}

	vector<string> ans(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < s[i].length(); j++) {
			ans[s[i][j]-'A'] += (char)s[i][j];
		}
	}

	map<vector<string>, int> d;
	d[s] = 0;
	queue<vector<string>> q;
	q.push(s);
	while (!q.empty()) {
		vector<string> now = q.front(); q.pop();
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (now[j].length() == 0) continue;
				vector<string> next(now);
				next[i].push_back(next[j].back());
				next[j].pop_back();
				if (d.count(next) == 0) {
					q.push(next);
					d[next] = d[now] + 1;
				}
			}
		}
	}

	cout << d[ans] << endl;

	return 0;
}

