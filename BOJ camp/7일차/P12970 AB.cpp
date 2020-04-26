#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

int N, K;
int DP[31][31][31][500];
string ans;

int countString(string str) {
	int ret = 0;
	for (int i = 0; i < str.length(); i++) {
		for (int j = i + 1; j < str.length(); j++) {
			if (str[i] < str[j]) {
				ret++;
			}
		}
	}
	return ret;
}

int f(int pos, int cntA, int cntB, int k) {
	if (pos == N) {
		if (k == K) {
			cout << ans << endl;
			return 1;
		}
		return 0;
	}
	
	int &ret = DP[pos][cntA][cntB][k];
	if (ret != -1) return ret;

	ans.push_back('A');
	ret = f(pos + 1, cntA + 1, cntB, k);
	if (ret) return ret;
	ans.pop_back();

	ans.push_back('B');
	ret = f(pos + 1, cntA, cntB + 1, k+cntA);
	if (ret) return ret;
	ans.pop_back();

	ans.push_back('C');
	ret = f(pos + 1, cntA, cntB, k+cntA+cntB);
	if (ret) return ret;
	ans.pop_back();

	return ret;
}


int main() {

	
	

	cin >> N >> K;	

	if (K != 0) {
		ans = "";
		memset(DP, -1, sizeof(DP));
		int ret = f(0, 0, 0,0);
		if (ret) {
		}
		else {
			cout << -1 << endl;
		}
	}
	else {
		for (int i = 0; i < N; i++) ans.push_back('A');
		cout << ans << endl;
	}

	return 0;
}

