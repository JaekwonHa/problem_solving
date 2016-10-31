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

	long long n;
	scanf("%lld", &n);
	long long fac = 1;
	for (int i = 1; i <= n; i++) {
		fac = fac*i;
	}
	printf("%lld\n", fac);
	return 0;
}