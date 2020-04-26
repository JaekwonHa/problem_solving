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


int main() {

	char str[200];
	scanf("%s", str);
	int len = strlen(str);
	int pos_point, pos_e;
	for (int i = 0; i < len; i++) {
		if (str[i] == '.') pos_point = i;
		if (str[i] == 'e') pos_e = i;
	}

	int b = 0;
	for (int i = pos_e+1; i < len; i++) {
		b *= 10;
		b += str[i] - '0';
	}

	char ans[300];
	int top=0;
	for (int i = 0; i < pos_e; i++) {
		if (top == pos_point + b) ans[top++] = '.', i--;
		else if(str[i]!='.') ans[top++] = str[i];
		else if (str[i] == 'e') break;
	}
	int c = pos_point + b - pos_e+1;
	while (c > 0) {
		ans[top++] = '0';
		c--;
	}
	int check = 0;
	for (int i = pos_point + b + 1; i < top; i++) {
		check += ans[i] - '0';
	}
	if (check == 0) {
		ans[pos_point + b] = '\0';
	}
	else {
		ans[top] = '\0';
	}
	printf("%s\n", ans);

	return 0;
}