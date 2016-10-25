#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 987654321

int N,DP[65][65][65];
int a[3];

int f(int a, int b, int c) {
	if (a <= 0 && b <= 0 && c <= 0) return 0;
	a = max(0, a);
	b = max(0, b);
	c = max(0, c);

	int &ret = DP[a][b][c];
	if (ret != -1) return ret;

	ret = INF;
	ret = min(ret, 1 + f(a - 9, b - 3, c - 1));
	ret = min(ret, 1 + f(a - 9, b - 1, c - 3));
	ret = min(ret, 1 + f(a - 3, b - 9, c - 1));
	ret = min(ret, 1 + f(a - 3, b - 1, c - 9));
	ret = min(ret, 1 + f(a - 1, b - 9, c - 3));
	ret = min(ret, 1 + f(a - 1, b - 3, c - 9));

	return ret;
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];

	memset(DP, -1, sizeof(DP));

	cout << f(a[0], a[1], a[2]) << endl;
	

	return 0;
}