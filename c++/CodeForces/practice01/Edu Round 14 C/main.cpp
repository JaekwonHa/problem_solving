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

int a1, a2, b;

int main() {

	char str[1000010];
	int pos = -1;
	scanf("%s", str);

	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == '.') pos = i;
	}
	b = INF;
	if (pos == -1) {
		pos = len;
	}
	int i = 0;
	int start = 0, end=len-1;
	while (str[start] == '0' || str[start] == '.') start++;
	while (str[end] == '0' || str[end] == '.') end--;
	
	if (b == INF) b = pos - start - 1;
	if (b < 0) b++;
	

	printf("%c", str[start]);
	if (start + 1 <= end) printf(".");
	for (int i = start+1; i <= end; i++) {
		if (str[i] == '.') continue;
		printf("%c", str[i]);
	}
	if (b != 0) {
		printf("E%d\n", b);
	}

	return 0;
}