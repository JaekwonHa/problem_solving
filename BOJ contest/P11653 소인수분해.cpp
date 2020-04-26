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
	for (int i = 2; i*i <= n; i++) {
		while (n%i==0) {
			n /= i;
			printf("%d\n", i);
		}
	}
	if (n > 1) printf("%d\n", n);

	return 0;
}