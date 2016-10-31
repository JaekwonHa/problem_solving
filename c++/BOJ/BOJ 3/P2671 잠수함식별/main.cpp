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

	int fa[10][2];
	memset(fa, -1, sizeof(fa));

	fa[0][0] = 1;
	fa[0][1] = 2;
	fa[1][1] = 3;
	fa[2][0] = 4;
	fa[3][0] = 1;
	fa[3][1] = 2;
	fa[4][0] = 5;
	fa[5][0] = 5;
	fa[5][1] = 6;
	fa[6][0] = 1;
	fa[6][1] = 7;
	fa[7][0] = 8;
	fa[7][1] = 7;
	fa[8][0] = 5;
	fa[8][1] = 3;

	char str[153];
	while (scanf("%s", str) == 1) {
		int n = 0;
		int c;
		for (int i = 0; i < strlen(str); i++) {
			c = str[i] - '0';
			n = fa[n][c];
			if (n == -1) break;
		}
		if (n == 3 || n == 6 || n == 7) printf("SUBMARINE\n");
		else printf("NOISE\n");
	}

	return 0;
}