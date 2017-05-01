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
#include <set>
#include <stack>
using namespace std;

#define INF 987654321
#define mod 1000000007
typedef long long ll;

int N, K, len;
int arr[100];

void solve() {
	int i,j,t;
	for (i = len; i > 0; i--) {
		t = 0;
		for (j = 0; j < i; j++) {
			if (arr[t] < arr[j]) {
				t = j;
			}
		}
		if (arr[t]!=0 && arr[i] < arr[t]) {
			swap(arr[i], arr[t]);
			return;
		}
	}
	for (i = len; i > 0; i--) {
		for (j = i - 1; j >= 0; j--) {
			if (arr[i] == arr[j]) return;
		}
	}
	swap(arr[1], arr[0]);
}

int main() {

	//freopen("input.txt", "r", stdin);

	string str;
	int K;
	cin >> str >> K;

	queue<string> q;
	q.push(str);
	while (K--) {
		int qSize = q.size();
		set<string> s;
		for (int i = 0; i < qSize; i++) {
			string now = q.front();
			q.pop();
			if (s.count(now)) continue;
			s.insert(now);
			for (int i = 0; i < now.length() - 1; i++) {
				for (int j = i + 1; j < now.length(); j++) {
					if (i==0 && now[j] == '0') continue;
					swap(now[i], now[j]);
					q.push(now);
					swap(now[i], now[j]);
				}
			}
		}
	}
	string ans = "0";
	while (!q.empty()) {
		ans = max(ans, q.front());
		q.pop();
	}
	if (ans[0] == '0') printf("-1\n");
	else cout << ans << endl;


	return 0;
}