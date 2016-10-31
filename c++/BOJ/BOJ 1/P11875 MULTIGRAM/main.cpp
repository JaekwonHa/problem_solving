#define _CRT_SECURE_NO_WARNINGS
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

string str;
string ans;
int len;

bool solve(int end) {
	if (len % (end + 1) != 0) return false;
	
	char str1[100001];
	char str2[100001];
	for (int i = 0; i <= end; i++) str1[i] = str[i];
	sort(str1, str1 + end+1);
	int k;
	for (int i = 1; i < len / (end + 1); i++) {
		for (int j = (end + 1)*i, k = 0; k <= end; j++, k++) {
			str2[k] = str[j];
		}
		sort(str2, str2 + end + 1);
		for (int j = 0; j <= end; j++) {
			if (str1[j] != str2[j]) {
				return false;
			}
		}
	}
	return true;
}

int main() {

	cin >> str;
	len = str.length();

	ans = "-1";
	for (int i = 0; i < len/2; i++) {
		if (solve(i)) {
			ans = str.substr(0, i+1);
			break;
		}
	}

	cout << ans << endl;

	return 0;
}