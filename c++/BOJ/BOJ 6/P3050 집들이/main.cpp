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

int r, c;
char m[410][410];
int sum[410][410];

int main() {

	int ans = 0;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", m[i]);
	}

	for (int i = 0; i < r; i++) {
		for (int j = 1; j <= c; j++) {
			sum[i][j] = sum[i][j - 1] + (m[i][j-1] == 'X');
		}
	}

	for (int s1 = 1; s1<= c; s1++) {
		for (int s2 = s1; s2 <= c; s2++) {
			int t1 = 0, t2 = 0;
			for (int i = 0; i < r; i++) {
				if (sum[i][s2] - sum[i][s1-1] == 0) {
					if (++t2 > t1) {
						t1 = t2;
					}
				}
				else {
					t2 = 0;
				}
			}

			if (t1 > 0) {
				ans = max(ans, 2 * t1 + 2 * (s2 - s1 + 1));
			}
		}
	}
	printf("%d\n", ans-1);

	return 0;
}