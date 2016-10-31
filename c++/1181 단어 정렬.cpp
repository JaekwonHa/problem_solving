#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <string>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;

int N;
map<string, int> m;

int main() {
	string str;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> str;
		m[str] = 1;
	}
	int i = 0;
	string arr[20001];
	for (auto a : m) {
		arr[i++] = a.first;
	}
	sort(arr, arr + m.size(), [](string a, string b) {
		if (a.length() != b.length()) {
			if (a.length() < b.length()) return 1;
			return 0;
		}
		if (a.compare(b) < 0) return 1;
		return 0;
	});
	for (i = 0; i < m.size(); i++) {
		cout << arr[i] << endl;
	}



	return 0;
}