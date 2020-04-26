#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;


int main() {

	char str[51];
	scanf("%s", str);
	
	int n = 0, cnt = 0;
	char type = 'w';
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == 'w' && type=='w') {
			n++;
		}
		else {
			if (i > 0 && type=='w' && str[i - 1] == 'w') type='o';
			if (str[i] == type) {
				int j;
				for (j = i; j < i+n; j++) {
					if (strlen(str) <= j || str[j] != type) {
						printf("0\n");
						return 0;
					}
				}
				if (type == 'o') type = 'l';
				else if (type == 'l') type = 'f';
				else if (type == 'f') type = 'w', n = 0;
				i = j-1;
			}
			else {
				printf("0\n");
				return 0;
			}
		}
	}
	if (str[strlen(str) - 1] == 'f') {
		printf("1\n");
	}
	else {
		printf("0\n");
	}
	

	return 0;
}

