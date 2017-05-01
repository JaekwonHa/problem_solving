#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

#define p 1000000007

int N, M, P;
long long DP[110][110];

long long f(int pos, int x) {
	int y = N - x;
	if (pos == P) {
		if (x == N) return 1; return 0;
	}
	long long &ret = DP[pos][x];
	if (ret != -1) return ret;
	ret = 0;
	ret += (f(pos + 1, x + 1)*y) % p;
	if(x-M >0) ret += (f(pos + 1, x)*(x-M)) % p;
	ret = ret%p;
	return ret;
}

int main() {

	cin >> N >> M >> P;
	
	DP[P+1][N] = 1;
	int y;
	for (int pos = P; pos >= 0; pos--) {
		for (int x = 0; x <= N; x++) {
			y = N - x;
			DP[pos][x] = (DP[pos + 1][x + 1] * y) % p;
			if(x-M>0)
				DP[pos][x] += (DP[pos + 1][x] * (x - M)) % p;
			DP[pos][x] = DP[pos][x] % p;
		}
	}
	cout << DP[1][0] << endl;
	/*
	memset(DP, -1, sizeof(DP));
	cout << f(0, 0) << endl;
	*/

	return 0;
}