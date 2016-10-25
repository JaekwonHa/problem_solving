#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char str[2][55];

int main() {

	cin >> str[0];
	cin >> str[1];

	int len1 = strlen(str[0]);
	int len2 = strlen(str[1]);
	int p1 = 0;
	int p2 = 0;

	bool ok = false;
	int cnt = 0;
	while (1) {
		if (cnt > 4) {
			ok = true;
			break;
		}
		if (str[0][p1] == str[1][p2]) {
			if (max(len1, len2) == max(p1, p2) + 1) {
				cnt++;
			}
			p1 = (p1 + 1) % len1;
			p2 = (p2 + 1) % len2;
		}
		else {
			break;
		}
	}
	ok ? printf("1\n") : printf("0\n");

	return 0;
}