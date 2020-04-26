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

int row[1001], col[1001];
char str[1001][1001];
int ansX, ansY;
int cnt;
bool notOk;

int main() {

	int r, c;
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		scanf("%s", str[i]);
		for (int j = 0; j < c; j++) {
			if (str[i][j] == '*') {
				row[i]++;
				col[j + 1]++;
				cnt++;
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int t = row[i] + col[j];
			if (str[i][j-1] == '*') t--;
			if (t >= cnt) {
				ansX = i, ansY = j;
			}
		}
	}


	if (ansX==0 && ansY==0) {
		printf("NO\n");
	}
	else {
		printf("YES\n%d %d\n", ansX, ansY);
	}



	return 0;
}