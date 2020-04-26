#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;

int N, M;
int arr[55];
char dir[55];
vector<pair<int, int>> v;

bool solve1() {
	map<int, int> m;
	set<map<int, int>> s;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) scanf("%d", &arr[i]), m[arr[i]] = 0;;
	scanf("%s", dir);

	s.insert(m);
	for (int i = 0; i < M; i++) {
		dir[i] == '+' ? m[arr[i]] += 1 : m[arr[i]] -= 1;
		s.insert(m);
	}
	if (s.size() == M + 1) return true;
	else return false;
}

bool solve2() {
	vector<pair<int, int>> v;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) scanf("%d", &arr[i]), v[i] = 0;;
	scanf("%s", dir);

	s.insert(m);
	for (int i = 0; i < M; i++) {
		dir[i] == '+' ? m[arr[i]] += 1 : m[arr[i]] -= 1;
		s.insert(m);
	}
	if (s.size() == M + 1) return true;
	else return false;
}

int main() {
	bool ok = solve1();

	if (ok) {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
	return 0;
}