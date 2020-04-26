#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;


char ch[51];
int row[51];
int col[51];

int main() {

	int r, c;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", ch);
		for (int j = 0; j < c; j++) {
			if (ch[j] == 'X') {
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	int ans = 0;
	int i, j;
	int rcnt = 0;
	int hcnt = 0;
	for (i = 0; i < r; i++) {
		if (row[i] == 0) rcnt++;
	}
	for (i = 0; i < c; i++) {
		if (col[i] == 0) hcnt++;
	}
	printf("%d\n", max(hcnt, rcnt));

	return 0;
}