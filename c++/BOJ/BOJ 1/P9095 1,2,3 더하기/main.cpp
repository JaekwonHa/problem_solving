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
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;

int DP[20];

int main() {

	int T;

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	for (int i = 4; i < 15; i++) {
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}

	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << DP[N] << endl;
	}

	return 0;
}