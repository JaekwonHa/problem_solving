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

char m[16][16];

int main() {

	for (int i = 0; i < 4; i++) {
		scanf("%s", m[i]);
	}

	int ans = 0;
	int num = -1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			num++;
			if (m[i][j] == '.') continue;
			int x, y;
			x = num % 4;
			y = num / 4;
			ans += abs((m[i][j]-'A')%4 - x) + abs((m[i][j] - 'A') / 4 - y);
			
		}
	}

	printf("%d\n", ans);

	return 0;
}