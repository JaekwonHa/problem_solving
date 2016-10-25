#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N, V;
char S[25],R[25];
bool ap['z'+1];

void fillString(char *s) {
	int len = strlen(s);
	while (strlen(s) < N) {
		for (char i = 'a'; i <= 'z'; i++) {
			if (ap[i] == false) {
				s[len] = i;
				s[len + 1] = '\0';
				ap[i] = true;
				break;
			}
		}
		len = strlen(s);
	}
}

char getEmpty() {
	char i;
	for (i = 'a'; i <= N + 'a' - 1; i++) {
		if (ap[i] == false) break;
	}
	ap[i] = true;
	return i;
}

bool up(char* s) {
	
	int n = strlen(s)-1;
	ap[s[n]] = false;
	while (n > 0) {
		if (s[n - 1] < s[n]) {
			for (char i = s[n-1]; i <= N+'a'-1; i++) {
				if (ap[i] == false) {
					ap[s[n - 1]] = false;
					s[n - 1] = i;
					ap[i] = true;
					for (int j = n; j < strlen(s); j++) {
						s[j] = getEmpty();
					}
					return true;
				}
			}
			return false;
		}
		n--;
		ap[s[n]] = false;
	}
	return false;
}

int inversion(char *s) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (s[i] > s[j]) ret++;
		}
	}
	return ret;
}

int main() {

	scanf("%d %d", &N, &V);
	scanf("%s", S);
	for (int i = 0; i < strlen(S); i++)
		ap[S[i]] = true;

	fillString(S);
	while (1) {
		if (inversion(S) >= V) {
			printf("%s\n", S);
			//return 0;
		}
		if (!up(S)) {
			break;
		}
	}
	printf("-1\n");
	return 0;
}