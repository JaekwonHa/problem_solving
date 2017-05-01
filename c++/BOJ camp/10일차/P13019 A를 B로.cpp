#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define INF 987654321
#define p 1000000007
typedef long long ll;

int countArr1['Z'];
int countArr2['Z'];

int main() {

	char str1[51], str2[51];
	scanf("%s %s", str1, str2);

	for (int i = 0; i < strlen(str1); i++) countArr1[str1[i]]++;
	for (int i = 0; i < strlen(str2); i++) countArr2[str2[i]]++;
	bool ok = true;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (countArr1[i] != countArr2[i]) {
			ok = false;
		}
	}
	if (ok == false) {
		printf("-1\n");
		return 0;
	}

	int len=strlen(str1), ans=0, t=len-1;
	for (int i = len - 1; i >= 0; i--) {
		if (str1[i] == str2[t]) {
			t--;
		}
		else {
			ans++;
		}
	}
	if (t == len-1) ans = -1;
	printf("%d\n", ans);
	return 0;
}

