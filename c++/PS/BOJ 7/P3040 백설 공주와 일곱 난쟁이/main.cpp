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


int arr[10];
vector<int> v;
bool ok;

void dfs(int pos, int sum) {
	if (sum == 100 && v.size() == 7) {
		ok = true;
		for (auto a : v) {
			printf("%d\n", a);
		}
		return;
	}
	if (ok) return;

	if (pos >= 9 || v.size()>=7) {
		return;
	}

	for (int i = pos; i < 9; i++) {
		v.push_back(arr[i]);
		dfs(i+1, sum + arr[i]);
		v.pop_back();
	}
}

int main() {

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 3; i++) {
		v.push_back(arr[i]);
		dfs(i+1, arr[i]);
		v.pop_back();
	}

	return 0;
}