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
#define p 1000000007
typedef long long ll;

int lenBomb;

char str[1000010];
char bomb[40];

int pos;
char STACK[1000010];

void BombCheck() {
	int temp = pos;
	bool ok = true;
	for (int i = lenBomb - 1; i >= 0; i--) {
		if (temp < 0) {
			ok = false;
			return;
		}
		if (STACK[temp] == bomb[i]) {
			temp--;
		}
		else {
			ok = false;
			return;
		}
	}
	if (ok == true) {
		pos = temp;
	}
}

int main() {

	
	scanf("%s", str);
	scanf("%s", bomb);

	lenBomb = strlen(bomb);
	int len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		STACK[pos] = str[i];
		if (STACK[pos] == bomb[lenBomb - 1]) {
			BombCheck();
		}
		pos++;
	}
	STACK[pos] = '\0';
	if (strlen(STACK)==0) {
		cout << "FRULA" << endl;
	}
	else {
		printf("%s\n", STACK);
	}

	return 0;
}