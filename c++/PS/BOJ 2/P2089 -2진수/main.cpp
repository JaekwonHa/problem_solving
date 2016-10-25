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

	long long number;
	scanf("%lld", &number);
	if (number == 0) {
		printf("0\n");
		return 0;
	}
	long long n = 1;
	long long p;
	if (number < 0) {
		while ((2 * (long long )(pow(4, n)) / 3ll < abs(number))) {
			n++;
		}
		n = n * 2;
		n--;
	}
	else {
		while ((1 * (long long)(pow(4, n)) / 3ll < number)) {
			n++;
		}
		n = n * 2 - 1;
		n--;
	}
	long long ans = pow(-2.0, n);
	n--;
	printf("1");
	for (long long i = n; i >= 0; i--) {
		long long d1 = abs(ans - number);
		long long t = pow(-2.0, i);
		long long d2 = abs(ans + pow(-2.0, i) - number);
		if (d1 >= d2) {
			printf("1");
			ans = ans + pow(-2.0, i);
		}
		else {
			printf("0");
		}
	}


	return 0;
}