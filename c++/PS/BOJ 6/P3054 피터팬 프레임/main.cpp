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

char frame[5][100];

int main() {

	char input[100];
	scanf("%s", input);

	int len = strlen(input);
	int i;
	for (i = 0; i < 4 * len; i++) {
		if (i % 4 == 2) {
			if ((i / 4) % 3 == 2) frame[0][i] = '*', frame[4][i] = '*';
			else frame[0][i] = '#', frame[4][i] = '#';
		}
		else {
			frame[0][i] = '.', frame[4][i] = '.';
		}
	}
	frame[0][i] = frame[4][i] = '.';

	for (i = 0; i < 4 * len; i++) {
		if (i % 4 == 1) {
			if ((i / 4) % 3 == 2) frame[1][i] = '*', frame[3][i] = '*';
			else frame[1][i] = '#', frame[3][i] = '#';
		}
		else if (i % 4 == 3) {
			if ((i / 4) % 3 == 2) frame[1][i] = '*', frame[3][i] = '*';
			else frame[1][i] = '#', frame[3][i] = '#';
		}
		else {
			frame[1][i] = '.', frame[3][i] = '.';
		}
	}
	frame[1][i] = frame[3][i] = '.';

	for (i = 0; i < 4 * len; i++) {
		if (i % 4 == 0) {
			if ((i / 4) % 3 == 2 || ((i-4) / 4) % 3 == 2) frame[2][i] = '*';
			else frame[2][i] = '#';
		}
		else if (i % 4 == 2) {
			frame[2][i] = input[(i / 4)];
		}
		else {
			frame[2][i] = '.';
		}
	}
	if (len % 3 == 0) frame[2][i] = '*';
	else frame[2][i] = '#';

	printf("%s\n", frame[0]);
	printf("%s\n", frame[1]);
	printf("%s\n", frame[2]);
	printf("%s\n", frame[3]);
	printf("%s\n", frame[4]);

		return 0;
}