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

	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}

	int a = 1;
	while (a*(3 * a + 3)+1 < n) a++;

	printf("%d\n", a+1);


	return 0;
}