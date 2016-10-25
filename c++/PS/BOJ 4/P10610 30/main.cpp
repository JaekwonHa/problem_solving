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


int main() {

	char str[100001];
	scanf("%s", str);

	int len = strlen(str);
	sort(str, str + len);

	if (str[0] == '0') {
		int sum = 0;
		for (int i = 1; i < len; i++) sum += str[i] - '0';
		if (sum % 3 == 0) {
			for (int i = len - 1; i >= 0; i--)
				printf("%c", str[i]);
			return 0;
		}
	}
	else {

	}
	printf("-1\n");
	return 0;
}