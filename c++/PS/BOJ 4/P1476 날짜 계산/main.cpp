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

	int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	int n;
	for (int i = S; ; i += 28) {
		if ((i - E) % 15 == 0 && (i - M) % 19 == 0) {
			n = i;
			break;
		}
	}
	printf("%d\n", n);
	return 0;
}