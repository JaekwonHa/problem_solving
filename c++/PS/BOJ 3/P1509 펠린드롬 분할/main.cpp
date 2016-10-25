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
#define mod 1000000007
typedef long long ll;

int len;
char str[2501];
bool chk[2501][2501];

bool checkPalindrome(int left, int right) {
	while (left < right) {
		if (str[left] != str[right]) return false;
		left++, right--;
	}
	return true;
}

int DP2[2501];
int f2(int pos) {
	if (pos == 0) return 0;
	int &ret = DP2[pos];
	if (ret != -1) return ret;

	ret = INF;
	for (int i = pos; i > 0; i--) {
		if (chk[pos][i]) {
			ret = min(ret, 1 + f2(i - 1));
		}
	}
	return ret;
}

int main() {

	freopen("input.txt", "r", stdin);
	
	scanf("%s", str+1);
	str[0] = '0';
	len = strlen(str);

	//memset(DP, -1, sizeof(DP));
	memset(DP2, -1, sizeof(DP2));
	for (int i = 1; i < len; i++) {
		chk[i][i]=true;
		for (int j = 1; j < i; j++) {
			if (str[i] == str[j]) chk[i][j] = chk[i - 1][j + 1];
			if (i-j == 1) chk[i][j] |= str[i] == str[i - 1];
		}
	}


	printf("%d\n", f2(len - 1));
	

	return 0;
}