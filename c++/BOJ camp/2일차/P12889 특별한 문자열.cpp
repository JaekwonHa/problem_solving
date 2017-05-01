#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

bool isSpecial(string str) {
	int n = str.length();
	for (int i = 1; i < n; i++) {
		if (str.substr(0, i) >= str.substr(i)) return false;
	}
	return true;
}

string solve(string str) {

	int n = str.length();

	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == '0') {
			string t = str;
			for (int j = i; j < n; j++) t[j] = '1';
			if (isSpecial(t)) {
				for (int j = i + 1; j < n; j++) {
					t[j] = '0';
					if (!isSpecial(t)) t[j] = '1';
				}
				return t;
			}
		}
	}
	return "-1";
}

int main() {

	string str, ans;
	cin >> str;

	cout << solve(str) << endl;

	return 0;
}

