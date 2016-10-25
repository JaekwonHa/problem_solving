#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

int main() {

	int M,S,x,n=20;
	scanf("%d", &M);
	char b[100];
	for (int i = 0; i < M; i++) {
		scanf("%s", b);
		switch (b[0]) {
		case 'a':
			if (b[1] == 'd') {
				scanf("%d", &x);
				x--;
				S = (S | (1 << x));
			}
			else {
				S = ((1 << n) - 1);
			}
			break;
		case 'r':
			scanf("%d", &x);
			x--;
			S = (S & ~(1 << x));
			break;
		case 'c':
			scanf("%d", &x);
			x--;
			if ((S&(1 << x))>0) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
			break;
		case 't':
			scanf("%d", &x);
			x--;
			S = (S ^ (1 << x));
			break;
		case 'e':
			S = 0;
			break;
		}
	}

	return 0;
}

