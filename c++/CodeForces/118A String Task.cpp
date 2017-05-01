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


int main() {

	char a[101];
	char b[201];
	scanf("%s", a);
	int len = strlen(a);
	int top = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] >= 'A' && a[i]<='Z') a[i] = a[i] + 'a' -'A';
		if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'u' || a[i] == 'o' || a[i]=='y') {

		}
		else {
			b[top++] = '.';
			
			b[top++] = a[i];
		}
	}
	b[top] = '\0';
	printf("%s\n", b);

	return 0;
}