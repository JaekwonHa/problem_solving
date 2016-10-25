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

	long long n, m;
	scanf("%lld %lld", &n, &m);

	long long a5 = 0, b5 = 0, c5 = 0;
	for (long long i = 1; i <= 13; i++) {
		a5 += n / (long long)(pow(5.0, i));
	}
	for (long long i = 1; i <= 13; i++) {
		b5 += m / (long long)(pow(5.0, i));
	}
	for (long long i = 1; i <= 13; i++) {
		c5 += (n - m) / (long long)(pow(5.0, i));
	}

	long long a2 = 0, b2 = 0, c2 = 0;
	long long p = 1;
	for (long long i = 1; p <= n; i++) {
		p *= 2;
		a2 += n / p;
	}
	p = 1;
	for (long long i = 1; p <= m; i++) {
		p *= 2;
		b2 += m / p;
	}
	p = 1;
	for (long long i = 1; p <= n - m; i++) {
		p *= 2;
		c2 += (n - m) / p;
	}
	a5 = a5 - (b5 + c5);
	a2 = a2 - (b2 + c2);

	printf("%d\n", min(a5, a2));

	return 0;
}