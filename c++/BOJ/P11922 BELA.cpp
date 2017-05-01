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

map<char, int> ds = {
	{ 'A',11 },
	{ 'K',4 },
	{ 'Q',3 },
	{ 'J',20 },
	{ 'T',10 },
	{ '9',14 },
	{ '8',0 },
	{ '7',0 },
};

map<char, int> ods = {
	{ 'A',11 },
	{ 'K',4 },
	{ 'Q',3 },
	{ 'J',2 },
	{ 'T',10 },
	{ '9',0 },
	{ '8',0 },
	{ '7',0 },
};

int main() {

	int N;
	char suit;
	scanf("%d %s", &N, &suit);

	int ans = 0;
	for (int i = 0; i < 4 * N; i++) {
		char input[3];
		scanf("%s", input);
		if (input[1] == suit) ans += ds[input[0]];
		else ans += ods[input[0]];
	}

	printf("%d\n", ans);

	return 0;
}