#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, point[51];
int DP[51][51][51];

int f_hongjun(int a, int k, int b) {
	if (a > N) return 0;
	if (k == 0) return f_hongjun(a + 1, k, b) + point[1];

	int &ret = DP[a][k][b];
	if (ret != -1) return ret;

	int plus;
	a == 1 ? plus = 0 : plus = 1;
	ret = 0;
	for (int i = 1; i <= k; i++) {
		ret = max(ret, f_hongjun(a + 1, k - i, b + i) + point[plus + i]);
	}
	return ret;
}

// a 처리한 정점, c 남은 정점, b 처리하지 않은 정점
int f_baekjon(int a, int c) {
	int b = N - a - c;
	if (a >= N) return 0;
	if (c == 0) return f_baekjon(a + 1, c) + point[1];

	int &ret = DP[a][0][c];
	if (ret != -1) return ret;

	int plus;
	a == 0 ? plus = 0 : plus = 1;
	ret = 0;
	for (int i = 1; i <= c; i++) {
		ret = max(ret, f_baekjon(a + 1, c - i) + point[plus + i]);
	}
	return ret;
}

int main() {

	cin >> N;
	for (int i = 1; i <= N-1; i++) cin >> point[i];

	memset(DP, -1, sizeof(DP));
	//cout << f_hongjun(1, N - 1, 2) << endl;
	cout << f_baekjon(0,N-1) << endl;

	return 0;
}